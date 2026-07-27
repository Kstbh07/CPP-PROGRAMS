class Solution {
public:
    bool canDivide(vector<int>& nums, int threshold, int divisor ) {
        int sum =0;
        for(int i=0; i<nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor;
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            
            if(canDivide(nums, threshold, mid)) {
                ans =mid;
                high = mid-1;
            }
            else{
                low =mid+1;
            }
        }
        return ans;
    }
};