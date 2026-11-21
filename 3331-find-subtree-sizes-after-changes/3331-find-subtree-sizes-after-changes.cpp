class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        vector<vector<int>> adj(n);
        vector<int> nearest(26, -1);

        vector<int> newParent(n, -1);

        // Build modified parent relationships
        vector<vector<int>> original(n);

        for (int i = 1; i < n; i++) {
            original[parent[i]].push_back(i);
        }

        function<void(int)> build = [&](int u) {
            int c = s[u] - 'a';
            int old = nearest[c];

            if (u != 0) {
                newParent[u] = (old == -1 ? parent[u] : old);
                adj[newParent[u]].push_back(u);
            }

            nearest[c] = u;

            for (int v : original[u]) {
                build(v);
            }

            nearest[c] = old;
        };

        build(0);

        // Iterative postorder traversal
        vector<int> order;
        stack<int> st;
        st.push(0);

        while (!st.empty()) {
            int u = st.top();
            st.pop();

            order.push_back(u);

            for (int v : adj[u]) {
                st.push(v);
            }
        }

        vector<int> ans(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int u = order[i];

            if (u != 0) {
                ans[newParent[u]] += ans[u];
            }
        }

        return ans;
    }
};