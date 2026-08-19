class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int pos = 0, neg = 1;
        for (int val : nums) {
            if (val > 0) {
                ans[pos] = val;
                pos += 2;
            } else {
                ans[neg] = val;
                neg += 2;
            }
        }
        return ans;
    }
};