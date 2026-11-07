import java.util.*;

class Solution {
    public int[] assignTasks(int[] servers, int[] tasks) {
        int n = servers.length;
        int m = tasks.length;

        int[] ans = new int[m];

        PriorityQueue<int[]> available = new PriorityQueue<>(
            (a, b) -> a[1] != b[1]
                ? a[1] - b[1]
                : a[0] - b[0]
        );

        PriorityQueue<long[]> busy = new PriorityQueue<>(
            (a, b) -> a[0] != b[0]
                ? Long.compare(a[0], b[0])
                : Long.compare(a[1], b[1])
        );

        for (int i = 0; i < n; i++) {
            available.offer(new int[]{i, servers[i]});
        }

        long time = 0;

        for (int i = 0; i < m; i++) {
            time = Math.max(time, i);

            while (!busy.isEmpty() && busy.peek()[0] <= time) {
                long[] server = busy.poll();
                available.offer(new int[]{
                    (int) server[1], servers[(int) server[1]]
                });
            }

            if (available.isEmpty()) {
                time = busy.peek()[0];

                while (!busy.isEmpty() && busy.peek()[0] <= time) {
                    long[] server = busy.poll();
                    available.offer(new int[]{
                        (int) server[1], servers[(int) server[1]]
                    });
                }
            }

            int[] server = available.poll();
            ans[i] = server[0];

            busy.offer(new long[]{
                time + tasks[i], server[0]
            });
        }

        return ans;
    }
}