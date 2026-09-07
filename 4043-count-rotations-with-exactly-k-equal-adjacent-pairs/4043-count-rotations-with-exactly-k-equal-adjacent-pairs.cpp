class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == s[(i + 1) % n])
                total++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int score = total;

            if (s[(i - 1 + n) % n] == s[i])
                score--;

            if (score == k)
                ans++;
        }

        return ans;
    }
};