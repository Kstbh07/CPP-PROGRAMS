class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        multiset<int> lo, hi;
        long long sumLo = 0, sumHi = 0;

        auto balance = [&]() {
            while (lo.size() > hi.size() + 1) {
                int v = *lo.rbegin();
                lo.erase(prev(lo.end()));
                sumLo -= v;
                hi.insert(v);
                sumHi += v;
            }

            while (lo.size() < hi.size()) {
                int v = *hi.begin();
                hi.erase(hi.begin());
                sumHi -= v;
                lo.insert(v);
                sumLo += v;
            }
        };

        auto add = [&](int v) {
            if (lo.empty() || v <= *lo.rbegin()) {
                lo.insert(v);
                sumLo += v;
            } else {
                hi.insert(v);
                sumHi += v;
            }
            balance();
        };

        auto remove = [&](int v) {
            auto it = lo.find(v);

            if (it != lo.end()) {
                lo.erase(it);
                sumLo -= v;
            } else {
                it = hi.find(v);
                hi.erase(it);
                sumHi -= v;
            }

            balance();
        };

        auto getCost = [&]() -> long long {
            long long med = *lo.rbegin();

            return med * (long long)lo.size() - sumLo
                 + sumHi - med * (long long)hi.size();
        };

        vector<long long> cost(n, 0);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const long long INF = LLONG_MAX / 4;

        vector<vector<long long>> dp(
            n + 1, vector<long long>(k + 1, INF)
        );

        dp[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;

            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(
                        dp[i][j],
                        dp[i - x][j - 1] + cost[i - x]
                    );
                }
            }
        }

        return dp[n][k];
    }
};