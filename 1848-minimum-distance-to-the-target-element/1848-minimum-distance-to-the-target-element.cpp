class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDist = nums.size();
        for(int i=start; i < nums.size(); i++){
            if ( target == nums[i] ) {
                minDist = i - start;
                break;
            } 
        }

        for (int i=start; i>=0; i--) {
            if ( target == nums[i] && start - i <= minDist) {
                minDist = start - i;
                break;
            }
        }
        return minDist;
    }
};