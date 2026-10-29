class Solution {
    int n, timer;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos, sz;
    vector<int> seg;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;

        int maxSubtree = 0;

        for (int v : adj[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            sz[u] += sub;

            if (sub > maxSubtree) {
                maxSubtree = sub;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h, const string& s) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h, s);

        for (int v : adj[u]) {
            if (v == parent[u] || v == heavy[u]) continue;
            decompose(v, v, s);
        }
    }

    void build(int node, int l, int r, const string& s,
               const vector<int>& nodeAtPos) {
        if (l == r) {
            seg[node] = 1 << (s[nodeAtPos[l]] - 'a');
            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, s, nodeAtPos);
        build(node * 2 + 1, mid + 1, r, s, nodeAtPos);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    void update(int node, int l, int r, int idx, int value) {
        if (l == r) {
            seg[node] = value;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(node * 2, l, mid, idx, value);
        else
            update(node * 2 + 1, mid + 1, r, idx, value);

        seg[node] = seg[node * 2] ^ seg[node * 2 + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;
        int res = 0;

        if (ql <= mid)
            res ^= query(node * 2, l, mid, ql, qr);

        if (qr > mid)
            res ^= query(node * 2 + 1, mid + 1, r, ql, qr);

        return res;
    }

    int pathQuery(int u, int v) {
        int mask = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            mask ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        mask ^= query(1, 0, n - 1, pos[u], pos[v]);

        return mask;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        timer = 0;

        adj.assign(n, {});
        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        sz.assign(n, 0);
        seg.assign(4 * n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1);
        decompose(0, 0, s);

        vector<int> nodeAtPos(n);
        for (int u = 0; u < n; u++)
            nodeAtPos[pos[u]] = u;

        build(1, 0, n - 1, s, nodeAtPos);

        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string type;
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u],
                       1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v);

                answer.push_back((mask & (mask - 1)) == 0);
            }
        }

        return answer;
    }
};