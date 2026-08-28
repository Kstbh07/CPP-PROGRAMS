class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int ans = 1950;
        int maxi = INT_MIN;
        for (int i = 1950; i <= 2050; i++) {
            int count = 0;

            for (const auto& person : logs) {
                if (i >= person[0] && i < person[1])
                    count++;
            }

            if (count > maxi) {
                maxi = count;
                ans = i;
            }
        }
        return ans;
    }
};