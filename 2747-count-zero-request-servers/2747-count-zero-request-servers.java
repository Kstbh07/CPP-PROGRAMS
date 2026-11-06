import java.util.*;

class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {
        int m = queries.length;

        Arrays.sort(logs, (a, b) -> Integer.compare(a[1], b[1]));

        int[][] q = new int[m][2];

        for (int i = 0; i < m; i++) {
            q[i][0] = queries[i];
            q[i][1] = i;
        }

        Arrays.sort(q, (a, b) -> Integer.compare(a[0], b[0]));

        int[] ans = new int[m];
        int[] count = new int[n + 1];

        int l = 0, r = 0, active = 0;

        for (int i = 0; i < m; i++) {
            int time = q[i][0];
            int idx = q[i][1];

            while (r < logs.length && logs[r][1] <= time) {
                int server = logs[r][0];

                if (count[server] == 0) {
                    active++;
                }

                count[server]++;
                r++;
            }

            while (l < r && logs[l][1] < time - x) {
                int server = logs[l][0];

                count[server]--;

                if (count[server] == 0) {
                    active--;
                }

                l++;
            }

            ans[idx] = n - active;
        }

        return ans;
    }
}