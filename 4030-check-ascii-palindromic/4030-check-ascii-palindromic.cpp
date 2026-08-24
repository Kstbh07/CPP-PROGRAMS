class Solution {
public:
    bool isPalindromic(string s) {
        string binary = "";

        for (char c : s) {
            int x = c;
            for (int i = 7; i >= 0; i--) {
                binary += ((x >> i) & 1) + '0';
            }
        }

        int left = 0;
        int right = binary.size() - 1;

        while (left < right) {
            if (binary[left] != binary[right])
                return false;

            left++;
            right--;
        }

        return true;
    }
};