class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {
        int prev = 0, ans = 0;
        for (int i = 0; i < requests.size(); i++) {
            ans += abs(prev - requests[i]);
            prev = requests[i];
        }
        return ans;
    }
};