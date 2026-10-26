class Solution {
public:
    int m, n;
    vector<vector<bool>> vis;
    vector<vector<int>>* gridPtr;
    long long sum;
    
    void dfs(int r, int c, vector<vector<int>>& grid) {
        if (r < 0 || c < 0 || r >= m || c >= n ||
            vis[r][c] || grid[r][c] == 0)
            return;
        
        vis[r][c] = true;
        sum += grid[r][c];
        
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }
    
    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<bool>(n, false));
        
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) {
                    sum = 0;
                    dfs(i, j, grid);
                    
                    if (sum % k == 0)
                        count++;
                }
            }
        }
        
        return count;
    }
};