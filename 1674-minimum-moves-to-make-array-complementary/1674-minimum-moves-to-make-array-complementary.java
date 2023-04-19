

class Solution {
    public int minMoves(int[] nums, int limit) {
        int n = nums.length;
        int[] ps = new int[limit * 2 + 2];
        for(int i = 0; i < n / 2; i++) {
            int v1 = nums[i], v2 = nums[n - 1 - i];
            ps[1 + Math.min(v1, v2)]--;
            ps[v1 + v2]--;
            ps[v1 + v2 + 1]++;
            ps[Math.max(v1, v2) + limit + 1]++;
        }
        int ans = n, curr = n;
        for(int i = 2; i <= limit * 2; i++) {
            curr += ps[i];
            ans = Math.min(ans, curr);
        }
        return ans;
    }
}

