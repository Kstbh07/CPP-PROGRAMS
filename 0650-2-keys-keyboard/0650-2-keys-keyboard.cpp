class Solution {
public:
    int solve(int screen, int copy, vector<vector<int>>& dp, int n) {
        if (screen == n) {
            return 0;
        }
        if (screen > n) {
            return 1e9;
        }
        if (dp[screen][copy] != -1) {
            return dp[screen][copy];
        }
        int copied = 1e9;

        if (screen != copy) {
            copied = 1 + solve(screen, screen, dp, n);
        }
        int paste = 1e9;
        if (copy > 0) {
            paste = 1 + solve(screen + copy, copy,dp,n);
        }
        return dp[screen][copy]=min(copied,paste);
        
    }
    int minSteps(int n) {
        if (n == 1)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(1, 0, dp, n);
    }
};