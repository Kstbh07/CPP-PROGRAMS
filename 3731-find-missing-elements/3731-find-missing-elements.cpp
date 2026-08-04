class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int minimum = INT_MAX, maximum = INT_MIN;
        for(int i=0; i<n; i++){
            minimum = min(minimum, nums[i]);
            maximum = max(maximum, nums[i]);
        }
        for(int i = minimum; i<maximum; i++) {
            bool found = false;
            for(int j=0; j<n; j++) {
                if(nums[j]==i){
                    found = true;
                    break;
                }
            }
            if(!found)
                ans.push_back(i);
        }
        return ans;
    }
};