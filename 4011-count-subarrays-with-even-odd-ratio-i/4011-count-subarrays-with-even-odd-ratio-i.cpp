class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int> even(n+1,0),odd(n+1,0);

        vector<long long> T(n+1);

        for(int i=0;i<n;i++){
            even[i + 1] = even[i];
            odd[i + 1] = odd[i];

            if (nums[i] % 2 == 0)
                even[i + 1]++;
            else
                odd[i + 1]++;

            T[i + 1] = 1LL * b * even[i + 1] - 1LL * a * odd[i + 1];
        }
        T[0] = 0;

        long long ans = 0;

        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r <= n; r++) {
                if (odd[r] > odd[l] && T[r] <= T[l])
                    ans++;
            }
        }

        return ans;
    }
};