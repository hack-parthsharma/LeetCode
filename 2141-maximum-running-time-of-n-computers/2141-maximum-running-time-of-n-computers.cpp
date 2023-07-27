class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long sum = accumulate(begin(batteries), end(batteries), 0LL);

    sort(begin(batteries), end(batteries));
    while (batteries.back() > sum / n) {
      sum -= batteries.back(), batteries.pop_back();
      --n;
    }
    return sum / n;
  }
};
