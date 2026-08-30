class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int ops = INT_MAX;
        for (int k = 0; k < n; k++) {
            int cost = k;
            for (int i = 0; i < n / 2; i++) {
                int left = (k + i) % n;
                int right = (k + n - 1 - i) % n;

                int a = s[left] - 'a';
                int b = s[right] - 'a';
                int diff1 = (a - b + 26) % 26, diff2 = (b - a + 26) % 26;
                cost += min(diff1, diff2);
            }
            ops = min(cost, ops);
        }
        return ops;
    }
};