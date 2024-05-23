// E.g. nums = [2, 3, 4, 4], k = 2
//
// subset[0] = [2, 4, 4']
// subset[1] = [1]
// count = {2: 1, 4: 2, 1: 1}



class Solution {
 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    constexpr int kMaxNum = 1000;
    vector<int> count(kMaxNum + 1);
    unordered_map<int, set<int>> modToSubset;

    for (const int num : nums) {
      ++count[num];
      modToSubset[num % k].insert(num);
    }

    int prevNum = -k;
    int skip = 0;
    int pick = 0;

    for (const auto& [_, subset] : modToSubset)
      for (const int num : subset) {
        const int nonEmptyCount = pow(2, count[num]) - 1;
        const int cacheSkip = skip;
        skip += pick;
        pick =
            nonEmptyCount * (1 + cacheSkip + (num - prevNum == k ? 0 : pick));
        prevNum = num;
      }

    return skip + pick;
  }
};
