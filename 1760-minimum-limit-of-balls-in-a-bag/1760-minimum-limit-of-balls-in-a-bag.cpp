class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        //find the theoretical min/max of penalty
        int max_penalty = 0;
        long long sum = 0;
        for (auto& n: nums){
            max_penalty = max(max_penalty, n);
            sum += n;
        }
        //the max of bags is nums.size() + maxOperations
        //the average of the ball is the theoretical min penalty
        int min_penalty = sum / (nums.size() + maxOperations);
        min_penalty = max(1, min_penalty); // in case of min_penalty is zero
        
        //binary search the real min penalty
        while (min_penalty < max_penalty) {
            int mid = min_penalty + (max_penalty - min_penalty) / 2;
            
            //if the penalty is `mid`, then how many operation we need
            int ops = 0;
            for (auto& n : nums){
                if (n <= mid) continue; //no need seperation
                ops += (n-1) / mid;
            }
            
            //if the operation we need is beyoned the limitation, 
            //then we find in the large part, else find in the small part.
            if (ops > maxOperations) {
                min_penalty = mid + 1;
            }else{
                max_penalty = mid;
            }
        }
        return min_penalty;
        
    }
};