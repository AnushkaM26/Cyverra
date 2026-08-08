import java.util.*;

class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        Arrays.sort(nums);
        int n = nums.length;
        
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : nums) {
            count.merge(x, 1, Integer::sum);
        }
        
        Set<Integer> candidates = new HashSet<>();
        for (int x : count.keySet()) {
            candidates.add(x);
            candidates.add(x - k);
            candidates.add(x + k);
            candidates.add(x - k - 1);
            candidates.add(x + k + 1);
        }
        
        int ans = 0;
        for (int m : candidates) {
            int l = lowerBound(nums, m - k);
            int r = upperBound(nums, m + k) - 1;
            if (r < l) continue;
            int window = r - l + 1;
            int cnt = count.getOrDefault(m, 0);
            int f = Math.min(window, numOperations + cnt);
            ans = Math.max(ans, f);
        }
        
        return ans;
    }

    private int lowerBound(int[] nums, int target) {
        int lo = 0, hi = nums.length;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (nums[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    
    private int upperBound(int[] nums, int target) {
        int lo = 0, hi = nums.length;
        while (lo < hi) {
            int mid = (lo + hi) >>> 1;
            if (nums[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
}