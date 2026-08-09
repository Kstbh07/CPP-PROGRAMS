class Solution {
public:
    string reversePrefix(string s, char ch) {
        int pos = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ch) {
                pos = i;
                break;
            }
        }
        if (pos != -1) {
            int i = 0, j = pos;
            while (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
};