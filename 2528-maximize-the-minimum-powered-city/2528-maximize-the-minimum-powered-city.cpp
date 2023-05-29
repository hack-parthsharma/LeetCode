class Solution {
 public:
  long long maxPower(vector<int>& stations, int r, int k) {
    long long left = *min_element(begin(stations), end(stations));
    long long right = accumulate(begin(stations), end(stations), 0LL) + k + 1;

    while (left < right) {
      const long long mid = (left + right) / 2;
      if (check(stations, r, k, mid))
        left = mid + 1;
      else
        right = mid;
    }

    return left - 1;
  }

 private:
  // Returns true if each city can have at least `minPower`.
  bool check(vector<int> stations, int r, int additionalStations,
             long long minPower) {
    const int n = stations.size();
    // Initilaize `power` as 0-th city's power - stations[r].
    long long power = accumulate(begin(stations), begin(stations) + r, 0LL);

    for (int i = 0; i < n; ++i) {
      if (i + r < n)
        power += stations[i + r];  // `power` = sum(stations[i - r..i + r]).
      if (power < minPower) {
        const long long requiredPower = minPower - power;
        if (requiredPower > additionalStations)  // No enough stations to plant.
          return false;
        // Greedily plant `requiredPower` power stations in the farthest place
        // to cover as many cities as possible.
        stations[min(n - 1, i + r)] += requiredPower;
        additionalStations -= requiredPower;
        power += requiredPower;
      }
      if (i - r >= 0)
        power -= stations[i - r];
    }

    return true;
  }
};
