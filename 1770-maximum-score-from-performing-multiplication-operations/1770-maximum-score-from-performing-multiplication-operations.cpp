const int MAX_SIZE = 1000;
class Solution {
private:
    int cache[MAX_SIZE][MAX_SIZE]; // num of left picked, num of right picked.
    int m, n;
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        memset(cache, -1, sizeof(cache));
        n = nums.size();
        m = multipliers.size();
        return maximumScoreDFS(nums, 0, n-1, multipliers, 0 );
    }
    
    int maximumScoreDFS(vector<int>& nums, int left, int right, 
                        vector<int>& multipliers, int midx) {
        
        if(midx >= m )  return 0;
        int nLeft = left; // num of left nums[] picked.
        int nRight = (n-1)-right; // num of right nums[] picked.
        if (cache[nLeft][nRight]!=-1) return cache[nLeft][nRight];
        
        int pickLeft = maximumScoreDFS(nums, left+1, right, multipliers, midx+1) +
            multipliers[midx] * nums[left];
        
        int pickRight = maximumScoreDFS(nums, left, right-1, multipliers, midx+1) +
            multipliers[midx] * nums[right];
        
        cache[nLeft][nRight] = max(pickLeft, pickRight);
        return cache[nLeft][nRight];
    }
};