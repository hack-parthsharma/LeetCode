class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    long long sum = accumulate(begin(batteries), end(batteries), 0LL);

    sort(begin(batteries), end(batteries));

    // Max battery is greater than the average, so it can last forever
    // Reduce the problem from size n to size n - 1
    while (batteries.back() > sum / n) {
      sum -= batteries.back(), batteries.pop_back();
      --n;
    }

    return sum / n;
  }
};
