class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = k;
        while (s.count(ans))
            ans += k;
        return ans;
    }
};