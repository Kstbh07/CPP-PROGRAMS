class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        freq[0] = 1;

        int prefixSum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            prefixSum += nums[i];

            int needed = prefixSum - k;

            if(freq.count(needed)) {
                count += freq[needed];
            }

            freq[prefixSum]++;
        }

        return count;
    }
};