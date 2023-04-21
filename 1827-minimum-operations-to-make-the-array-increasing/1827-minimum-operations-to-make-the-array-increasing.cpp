class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ins = 0;
        int top = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if (nums[i] > top){
                top = nums[i];
            }else{
                ins += (top - nums[i] + 1);
                top++;
            }
        }
        return ins;
    }
};