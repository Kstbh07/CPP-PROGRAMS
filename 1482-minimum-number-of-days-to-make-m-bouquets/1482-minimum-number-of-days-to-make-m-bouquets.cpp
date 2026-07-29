class Solution {
public:
    bool canMake(vector<int>& bloomDay, int m, int k, int day) {
        int count = 0;
        int bouquet =0;
        for(int i=0; i<bloomDay.size(); i++) {
            if(bloomDay[i] <= day) {
                count++;
                if(count == k) {
                    bouquet++;
                    count =0;
                }
            }
            else {
                count =0;
            }
        }
        return bouquet >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans =-1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(canMake(bloomDay, m, k, mid)) {
                ans = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ans;
    }
};