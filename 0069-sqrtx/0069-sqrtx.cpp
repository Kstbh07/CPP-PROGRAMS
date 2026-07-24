class Solution {
public:
    int mySqrt(int x) {
        int lw = 0, hi = x;
        int ans = 0;
        while(lw<=hi) {
            int mid = lw+(hi-lw)/2;
            long long sq = 1LL *mid*mid;
            if(sq == x) {
                ans = mid;
                return mid;
            }
            else if(sq<x) {
                ans = mid;
                lw=mid+1;
            }
            else {
                hi = mid-1;
            }
        }
        return ans;
    }
};