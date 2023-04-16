 class Solution {
        public int minOperations(int[] nums, int x) {
            int target = -x;
            int len = nums.length;
            for (int num : nums) {
                target += num;
            }
            // corner case
            if (target == 0) {
                return len;
            }
            // normal case
            int res = Integer.MIN_VALUE;
            int sum = 0;
            HashMap<Integer, Integer> map = new HashMap<>(); // sum value 0-i => index i
            map.put(0, -1);
            for (int i = 0; i < len; i++) {
                sum += nums[i];
                if (map.containsKey(sum - target)) {
                    res = Math.max(res, i - map.get(sum - target));
                }
                map.put(sum, i);
            }
            return res == Integer.MIN_VALUE ? -1 : len - res;
        }
    }