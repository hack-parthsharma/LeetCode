class Solution {
 public:
  long long minCost(vector<int>& basket1, vector<int>& basket2) {
    vector<int> swapped;
    unordered_map<int, int> count;

    for (const int b : basket1)
      ++count[b];

    for (const int b : basket2)
      --count[b];

    for (const auto& [num, freq] : count) {
      if (freq % 2 != 0)
        return -1;
      for (int i = 0; i < abs(freq) / 2; ++i)
        swapped.push_back(num);
    }

    const int minNum = min(*min_element(begin(basket1), end(basket1)),
                           *min_element(begin(basket2), end(basket2)));
    const auto midIt = begin(swapped) + swapped.size() / 2;
    nth_element(begin(swapped), midIt, end(swapped));
    return accumulate(begin(swapped), midIt, 0LL,
                      [minNum](long long subtotal, int num) {
      return subtotal + min(2 * minNum, num);
    });
  }
};
