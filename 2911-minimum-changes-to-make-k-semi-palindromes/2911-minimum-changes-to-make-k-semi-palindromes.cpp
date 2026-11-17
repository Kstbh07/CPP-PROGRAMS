
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        // cost[i][j] = minimum changes to make
        // substring s[i...j] a semi-palindrome
        vector<vector<int>> cost(n, vector<int>(n, INF));

        // Precompute costs
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                int len = j - i + 1;

                // Try every valid divisor
                for (int d = 1; d < len; d++) {

                    if (len % d != 0)
                        continue;

                    int changes = 0;

                    for (int offset = 0; offset < d; offset++) {

                        int l = i + offset;
                        int r = j - d + 1 + offset;

                        while (l < r) {
                            if (s[l] != s[r])
                                changes++;

                            l += d;
                            r -= d;
                        }
                    }

                    cost[i][j] = min(cost[i][j], changes);
                }
            }
        }

        // dp[i][j] = minimum changes to divide
        // first i characters into j parts
        vector<vector<int>> dp(n + 1,
                               vector<int>(k + 1, INF));

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {

                for (int p = 0; p < i - 1; p++) {

                    if (dp[p][j - 1] == INF)
                        continue;

                    dp[i][j] = min(
                        dp[i][j],
                        dp[p][j - 1] + cost[p][i - 1]
                    );
                }
            }
        }

        return dp[n][k];
    }
};
