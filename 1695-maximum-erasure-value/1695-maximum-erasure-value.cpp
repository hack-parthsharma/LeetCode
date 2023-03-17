class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        //unordered_map<int, int> pos;
        const int NIL = -1;
        int pos[10001];
        memset(pos, NIL, sizeof(pos));
        
        int start=0;
        int max_sum =0, sum = 0;
 
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            // if find duplicated number
            if ( pos[n] != NIL) {
                max_sum = max(max_sum, sum);
                //remove the previous numbers until to duplicatied position 
                for(;start <= pos[n]; start++){
                    sum -= nums[start];
                    pos[nums[start]] = NIL;
                }
            }
            sum += n;
            pos[n] = i;
        }
        max_sum = max( max_sum , sum );
        return max_sum;
    }
};