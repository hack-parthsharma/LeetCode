class Solution {
 public:
  int numberOfGoodSubsets(vector<int>& nums) {
    const vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    const int n = 1 << primes.size();
    const int maxNum = *max_element(begin(nums), end(nums));
    vector<long> dp(n);
    vector<int> count(maxNum + 1);

    dp[0] = 1;

    for (const int num : nums)
      ++count[num];

    for (int num = 2; num <= maxNum; ++num) {
      if (count[num] == 0)
        continue;
      if (num % 4 == 0 || num % 9 == 0 || num % 25 == 0)
        continue;
      const int numPrimesMask = getPrimesMask(num, primes);
      for (int primesMask = 0; primesMask < n; ++primesMask) {
        if ((primesMask & numPrimesMask) > 0)
          continue;
        const int nextPrimesMask = primesMask | numPrimesMask;
        dp[nextPrimesMask] += dp[primesMask] * count[num];
        dp[nextPrimesMask] %= kMod;
      }
    }

    return myPow(2, count[1]) *
           (accumulate(begin(dp) + 1, end(dp), 0L) % kMod) % kMod;
  }

 private:
  static constexpr int kMod = 1'000'000'007;

  int getPrimesMask(int num, const vector<int>& primes) {
    int primesMask = 0;
    for (int i = 0; i < primes.size(); ++i)
      if (num % primes[i] == 0)
        primesMask |= 1 << i;
    return primesMask;
  }

  int myPow(long x, int n) {
    if (n == 0)
      return 1;
    if (n & 1)
      return x * myPow(x, n - 1) % kMod;
    return myPow(x * x % kMod, n / 2);
  }
};
