class Solution {
    public int[] runningSum(int[] nums) {
        
        int len = nums.length;
        int[] runningSumAr = new int[len];
        
        int sumSoFar = 0;
        
        for(int i=0; i<len; i++){
            sumSoFar += nums[i];
            
            runningSumAr[i] = sumSoFar;
        }
        
        return runningSumAr;
    }
}