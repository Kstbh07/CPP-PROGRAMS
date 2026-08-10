class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(prices.begin(), prices.end());
        sort(discounts.begin(), discounts.end());

        int n = discounts.size();
        int m = prices.size();
        int i = n - 1;
        int j = m - 1;
        double ans = 0;
        while (i >= 0 && j >= 0) {
            ans += ((double)prices[j] * (100 - (double)discounts[i])) / 100;
            i--;
            j--;
        }
        while (j >= 0) {
            ans += (double)prices[j];
            j--;
        }
        return ans;
    }
};