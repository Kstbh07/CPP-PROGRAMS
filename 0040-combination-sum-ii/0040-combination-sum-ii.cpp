class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int idx, int target, vector<int>& candidates) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Pruning
            if (candidates[i] > target)
                break;

            path.push_back(candidates[i]);
            dfs(i + 1, target - candidates[i], candidates);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates);
        return ans;
    }
};