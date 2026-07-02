class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;

        stringstream ss(path);

        while (getline(ss, cur, '/')) {
            if (cur == "" || cur == ".")
                continue;
            else if (cur == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(cur);
            }
        }

        string ans;
        for (string &dir : st)
            ans += "/" + dir;

        return ans.empty() ? "/" : ans;
    }
};