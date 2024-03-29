class Solution {
 public:
  int earliestSecondToMarkIndices(vector<int>& nums,
                                  vector<int>& changeIndices) {
    int l = 0;
    int r = changeIndices.size() + 1;

    while (l < r) {
      const int m = (l + r) / 2;
      if (canMark(nums, changeIndices, m))
        r = m;
      else
        l = m + 1;
    }

    return l <= changeIndices.size() ? l : -1;
  }

 private:
  bool canMark(const vector<int>& nums, const vector<int>& changeIndices,
               int second) {
    int numMarked = 0;
    int decrement = 0;
    vector<int> indexToLastSecond(nums.size(), -1);

    for (int i = 0; i < second; ++i)
      indexToLastSecond[changeIndices[i] - 1] = i;

    for (int i = 0; i < second; ++i) {
      const int index = changeIndices[i] - 1;  
      if (i == indexToLastSecond[index]) {
        if (nums[index] > decrement)
          return false;
        decrement -= nums[index];
        ++numMarked;
      } else {
        ++decrement;
      }
    }

    return numMarked == nums.size();
  }
};