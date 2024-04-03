class Solution {
public:
  int minOperations(int k) {
    const int x = ceil(sqrt(k));
    const int y = (k - 1) / x + 1 - 1;  
    return x - 1 + y;
  }
};