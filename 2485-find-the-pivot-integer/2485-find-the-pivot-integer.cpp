class Solution {
 public:
  int pivotInteger(int n) {
    //               x = sqrt((n^2 + n) / 2)
    const int y = (n * n + n) / 2;
    const int x = sqrt(y);
    return x * x == y ? x : -1;
  }
};
