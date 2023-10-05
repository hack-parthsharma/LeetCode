class Solution {
 public:
  vector<int> majorityElement(vector<int>& nums) {
    vector<int> ans;
    int candidate1 = 0;
    int candidate2 = 1;   
    int countSoFar1 = 0;  
    int countSoFar2 = 0;  

    for (const int num : nums)
      if (num == candidate1) {
        ++countSoFar1;
      } else if (num == candidate2) {
        ++countSoFar2;
      } else if (countSoFar1 == 0) {  
        candidate1 = num;
        ++countSoFar1;
      } else if (countSoFar2 == 0) {  
        candidate2 = num;
        ++countSoFar2;
      } else {  
        --countSoFar1;
        --countSoFar2;
      }

    const int count1 = count(begin(nums), end(nums), candidate1);
    const int count2 = count(begin(nums), end(nums), candidate2);

    if (count1 > nums.size() / 3)
      ans.push_back(candidate1);
    if (count2 > nums.size() / 3)
      ans.push_back(candidate2);
    return ans;
  }
};
