class Solution {
public:
    bool canEat(vector<int>& piles, int h, int speed) {
        long long hours = 0;
        for(int i=0; i<piles.size(); i++) {
            hours += (piles[i] + speed - 1) / speed;
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = *max_element(piles.begin(), piles.end());
        int ans =0;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(canEat(piles,h,mid)) {
                ans=mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};