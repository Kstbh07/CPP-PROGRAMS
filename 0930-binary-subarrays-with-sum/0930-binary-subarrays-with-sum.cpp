class Solution {
public:

    int helper(vector<int>& nums, int goal){
        int n=nums.size();
        if(goal<0) return 0;
        int count=0;
        int l=0;
        int r=0;
        int curr_sum=0;
        while(r<n){
            curr_sum+=nums[r];
            while(curr_sum>goal) {
                curr_sum-=nums[l];
                l++;
            }
            count+=(r-l+1);
            r++;


        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal)-helper(nums,goal-1);
        
    }
};