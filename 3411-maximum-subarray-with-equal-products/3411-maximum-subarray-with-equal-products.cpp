
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = min(n, 2);

        for (int i = 0; i < n; i++) {
            int mask = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];
                int cur = 0;

                if (x % 2 == 0) cur |= 1;
                if (x % 3 == 0) cur |= 2;
                if (x % 5 == 0) cur |= 4;
                if (x % 7 == 0) cur |= 8;

                if (mask & cur) break;

                mask |= cur;
                ans = max(ans, j - i + 1);
            }
        }

        return ans;
    }
};
