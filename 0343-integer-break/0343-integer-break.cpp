class Solution {
 public:
  int integerBreak(int n) {
    // (and 1 is wasteful).
    // Also, 3 * 3 is better than 2 * 2 * 2, so we never use 2 more than twice.
    if (n == 2)  // 1 * 1
      return 1;
    if (n == 3)  // 1 * 2
      return 2;

    int ans = 1;

    while (n > 4) {
      n -= 3;
      ans *= 3;
    }
    ans *= n;

    return ans;
  }
};
