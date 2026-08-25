class Solution {
public:
    int solve(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if (i == n) {
            return 1;
        }
        if (s[i] == '0') {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int ways = solve(i + 1, s, dp);
        if (i + 1 < n) {
            int num = (s[i] - '0') * 10 + (s[i + 1] - '0');
            if (num > 9 && num < 27) {
                ways += solve(i + 2, s, dp);
            }
        }
        return dp[i] = ways;
    }
    int solvetab(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                continue;
            }
            dp[i] = dp[i + 1];
            if (i + 1 < n) {
                int num = (s[i] - '0') * 10 + (s[i + 1] - '0');

                if (num >= 10 && num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }
        return dp[0];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);

        return solvetab(s);
    }
};