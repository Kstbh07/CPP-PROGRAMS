class Solution {
public:
    int ans = 0;

    void solve(int row, int n,
               vector<bool>& col,
               vector<bool>& diag1,
               vector<bool>& diag2) {

        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;

            solve(row + 1, n, col, diag1, diag2);

            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

    int totalNQueens(int n) {
        vector<bool> col(n, false);
        vector<bool> diag1(2 * n, false);
        vector<bool> diag2(2 * n, false);

        solve(0, n, col, diag1, diag2);
        return ans;
    }
};