class Solution {
public:
    vector<string> ans;

    void backtrack(string &s, int idx, int parts, string curr) {
        if (parts == 4 && idx == s.size()) {
            curr.pop_back(); 
            ans.push_back(curr);
            return;
        }

        if (parts == 4 || idx == s.size())
            return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string part = s.substr(idx, len);
            
            if (part.size() > 1 && part[0] == '0')
                break;

           
            if (stoi(part) > 255)
                continue;

            backtrack(s, idx + len, parts + 1, curr + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 || s.size() > 12)
            return {};

        backtrack(s, 0, 0, "");
        return ans;
    }
};