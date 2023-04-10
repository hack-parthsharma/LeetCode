class Solution {
 public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    constexpr int kMod = 1'000'000'007;
    sort(begin(horizontalCuts), end(horizontalCuts));
    sort(begin(verticalCuts), end(verticalCuts));

    // Max gap of each direction.
    int maxGapX = max(verticalCuts[0], w - verticalCuts.back());
    int maxGapY = max(horizontalCuts[0], h - horizontalCuts.back());

    for (int i = 1; i < verticalCuts.size(); ++i)
      maxGapX = max(maxGapX, verticalCuts[i] - verticalCuts[i - 1]);

    for (int i = 1; i < horizontalCuts.size(); ++i)
      maxGapY = max(maxGapY, horizontalCuts[i] - horizontalCuts[i - 1]);

    return static_cast<long>(maxGapX) * maxGapY % kMod;
  }
};
