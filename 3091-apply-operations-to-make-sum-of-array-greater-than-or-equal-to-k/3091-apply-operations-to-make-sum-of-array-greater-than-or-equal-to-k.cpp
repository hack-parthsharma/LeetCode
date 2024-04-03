class Solution {
 public:
  int minOperations(int k) {
    // Optimally, `x` should equal to `1 + y`, implying that x^2 >= k, and
    // hence, x >= sqrt(k) and y = ceil(k / x) - 1.
    const int x = ceil(sqrt(k));
    const int y = (k - 1) / x + 1 - 1;  
    return x - 1 + y;
  }
};