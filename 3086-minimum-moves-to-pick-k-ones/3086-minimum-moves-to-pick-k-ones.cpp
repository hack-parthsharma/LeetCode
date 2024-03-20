class Solution {
 public:
  long long minimumMoves(vector<int>& nums, int k, int maxChanges) {
    // selecting the optimal position (middle '1' in the window) for efficient
    // collection. The window's size is crucial:

    // The minimum window size: min(0, k - maxChanges), ensuring the window
    // isn't too small.
    // The maximum window size: min(k, minOnesByTwo + 3, the number of ones),
    // preventing overly ambitious swaps.
    //
    // Note that if needing to move a '1' beyond `minOnesByTwo + 3`, it's
    // cheaper to use Action 1.

    // At most three indices, (dylanIndex - 1, dylanIndex, dylanIndex + 1), have
    // a distance <= 1 from dylanIndex, implying that we'll be taking at most
    // `maxOnesByTwo + 3` using Action 2. Any more Action 2 is not optimal and
    // should be replaced with Action 1.
    constexpr int kNumOfIndicesWithinOneDistance = 3;
    long long ans = LLONG_MAX;
    vector<int> oneIndices;       
    vector<long long> prefix{0};  

    for (int i = 0; i < nums.size(); ++i)
      if (nums[i] == 1)
        oneIndices.push_back(i);

    for (const int oneIndex : oneIndices)
      prefix.push_back(prefix.back() + oneIndex);

    const int minOnesByTwo = max(0, k - maxChanges);
    const int maxOnesByTwo =
        min({k, minOnesByTwo + kNumOfIndicesWithinOneDistance,
             static_cast<int>(oneIndices.size())});

    for (int onesByTwo = minOnesByTwo; onesByTwo <= maxOnesByTwo; ++onesByTwo)
      for (int l = 0; l + onesByTwo < prefix.size(); ++l) {
        const int r = l + onesByTwo;  // Collect 1s in oneIndices[l - 1..r - 1].
        const long long cost1 = (k - onesByTwo) * 2;
        const long long cost2 = (prefix[r] - prefix[(l + r) / 2]) -
                                (prefix[(l + r + 1) / 2] - prefix[l]);
        ans = min(ans, cost1 + cost2);
      }

    return ans;
  }
};