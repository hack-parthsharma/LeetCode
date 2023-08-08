class Solution {
 public:
  long long findMaximumElegance(vector<vector<int>>& items, int k) {
    long long ans = 0;
    long long totalProfit = 0;
    // Store seen `category`s.
    unordered_set<int> seenCategories;
    // Store duplicate profits decreasingly.
    stack<int> decreasingDuplicateProfits;

    sort(items.begin(), items.end(), greater<>());

    for (int i = 0; i < k; i++) {
      const int profit = items[i][0];
      const int category = items[i][1];
      totalProfit += profit;
      if (seenCategories.count(category))
        decreasingDuplicateProfits.push(profit);
      else
        seenCategories.insert(category);
    }

    ans = totalProfit + 1LL * seenCategories.size() * seenCategories.size();

    for (int i = k; i < items.size(); ++i) {
      const int profit = items[i][0];
      const int category = items[i][1];
      if (!seenCategories.count(category) &&
          !decreasingDuplicateProfits.empty()) {
        // If this is a new category we haven't seen before, it's worth
        // considering taking it and replacing the one with the least profit
        // since it will increase the distinct_categories and potentially result
        // in a larger total_profit + distinct_categories^2.
        totalProfit -= decreasingDuplicateProfits.top(),
            decreasingDuplicateProfits.pop();
        totalProfit += profit;
        seenCategories.insert(category);
        ans = max(ans, static_cast<long long>(totalProfit +
                                              1LL * seenCategories.size() *
                                                  seenCategories.size()));
      }
    }

    return ans;
  }
};
