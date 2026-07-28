class Solution {
public:
    bool canShip(vector<int>& weights, int days, int capacity) {
       int dayused = 1;
       int currWeight = 0;
       for(int i=0; i<weights.size(); i++) {
        if(currWeight + weights[i] <= capacity) {
            currWeight += weights[i];
        }
        else {
            dayused++;
            currWeight = weights[i];
        }
       }
       return dayused <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(),0);
        int ans = -1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(canShip(weights, days, mid)) {
                ans=mid;
                high = mid-1;
            }
            else {
                low =mid+1;
            }
        }
        return ans;
    }
};