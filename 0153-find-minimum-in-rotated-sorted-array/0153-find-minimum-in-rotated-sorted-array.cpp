class Solution {
public:
    int findMin(vector<int>& nums) {
        int tar = *min_element(nums.begin(), nums.end());
        return tar;
    }
};