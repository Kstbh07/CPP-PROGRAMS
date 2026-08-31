class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string n = to_string(num);
        int ans = 0;
        int i = 0;
        while (i + k <= n.size()) {
            int subNum = stoi(n.substr(i, k));
            if (subNum != 0 && num % subNum == 0)
                ans++;
            i++;
        }
        return ans;
    }
};