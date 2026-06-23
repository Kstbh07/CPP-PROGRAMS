class Solution {
public:
    string countAndSay(int n) {
        string res = "1";

        for (int k = 1; k < n; k++) {
            string temp = "";
            int count = 1;

            for (int i = 1; i < res.size(); i++) {
                if (res[i] == res[i - 1])
                    count++;
                else {
                    temp += to_string(count);
                    temp += res[i - 1];
                    count = 1;
                }
            }

            temp += to_string(count);
            temp += res.back();

            res = temp;
        }

        return res;
    }
};