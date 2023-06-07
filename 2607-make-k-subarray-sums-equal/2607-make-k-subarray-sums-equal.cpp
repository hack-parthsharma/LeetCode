class Solution {
 public:
  long long makeSubKSumEqual(vector<int>& arr, int k) {
    // If the sum of each subarray of length k is equal, `arr` must have
    // repeated pattern of size k. E.g. arr = [1, 2, 3, ...] and k = 3, to have
    // sum([1, 2, 3)] == sum([2, 3, x]), x must be 1. Therefore, arr[i] ==
    // arr[(i + k) % n] for every i.
    const int n = arr.size();
    long long ans = 0;
    vector<bool> seen(n);

    for (int i = 0; i < n; ++i) {
      vector<int> groups;
      int j = i;
      while (!seen[j]) {
        groups.push_back(arr[j]);
        seen[j] = true;
        j = (j + k) % n;
      }
      nth_element(begin(groups), begin(groups) + groups.size() / 2,
                  end(groups));
      for (const int num : groups)
        ans += abs(num - groups[groups.size() / 2]);
    }

    return ans;
  }
};
