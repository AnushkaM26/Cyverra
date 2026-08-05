import java.util.*;

class Solution {
    public List<Integer> remainingMethods(int n, int k, int[][] invocations) {

        List<List<Integer>> calls = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            calls.add(new ArrayList<>());
        }

        for (int[] edge : invocations) {
            calls.get(edge[0]).add(edge[1]);
        }

        boolean[] isSuspicious = new boolean[n];
        Queue<Integer> q = new LinkedList<>();

        q.offer(k);
        isSuspicious[k] = true;

        while (!q.isEmpty()) {
            int current = q.poll();

            for (int next : calls.get(current)) {
                if (!isSuspicious[next]) {
                    isSuspicious[next] = true;
                    q.offer(next);
                }
            }
        }

        for (int[] edge : invocations) {
            int caller = edge[0];
            int called = edge[1];

            if (!isSuspicious[caller] && isSuspicious[called]) {
                List<Integer> allMethods = new ArrayList<>();

                for (int i = 0; i < n; i++) {
                    allMethods.add(i);
                }

                return allMethods;
            }
        }

        List<Integer> remaining = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            if (!isSuspicious[i]) {
                remaining.add(i);
            }
        }

        return remaining;
    }
}