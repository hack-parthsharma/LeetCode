class Solution {
 public:
  bool find132pattern(vector<int>& nums) {
    stack<int> stack;  
    int ak = INT_MIN;  

    for (int i = nums.size() - 1; i >= 0; --i) {
      // Ai < ak, we're done because ai must also smaller than aj
      if (nums[i] < ak)
        return true;
      while (!stack.empty() && stack.top() < nums[i])
        ak = stack.top(), stack.pop();
      stack.push(nums[i]);  // nums[i] is a candidate of aj
    }

    return false;
  }
};
