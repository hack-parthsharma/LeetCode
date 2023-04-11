class Solution {
 public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    if (bloomDay.size() < static_cast<long>(m) * k)
      return -1;

    int l = *min_element(begin(bloomDay), end(bloomDay));
    int r = *max_element(begin(bloomDay), end(bloomDay));

    while (l < r) {
      const int mid = (l + r) / 2;
      if (getBouquetCount(bloomDay, k, mid) >= m)
        r = mid;
      else
        l = mid + 1;
    }

    return l;
  }

 private:
  // Returns # of bouquet (k flowers needed) can be made after `waitingDays`.
  int getBouquetCount(const vector<int>& bloomDay, int k, int waitingDays) {
    int bouquetCount = 0;
    int requiredFlowers = k;
    for (const int day : bloomDay)
      if (day > waitingDays) {
        // Reset `requiredFlowers` since there was not enough adjacent flowers.
        requiredFlowers = k;
      } else if (--requiredFlowers == 0) {
        // Use k adjacent flowers to make a bouquet.
        ++bouquetCount;
        requiredFlowers = k;
      }
    return bouquetCount;
  }
};
