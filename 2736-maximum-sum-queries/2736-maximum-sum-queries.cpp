struct Pair {
  int x;
  int y;
};

struct IndexAndQuery {
  int index;  // the index in `queries`
  int minX;   // queries[i] := (minX, minY)
  int minY;
};

class Solution {
 public:
  vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    const vector<Pair> pairs = getPairs(nums1, nums2);
    const vector<IndexAndQuery> indexAndQueries = getIndexAndQueries(queries);
    vector<int> ans(queries.size());
    vector<pair<int, int>> stack;  // [(y, x + y)]

    int i = 0;
    for (const auto& [index, minX, minY] : indexAndQueries) {
      while (i < pairs.size() && pairs[i].x >= minX) {
        const auto [x, y] = pairs[i++];
        // x + y is a better candidate. Given that x is decreasing, the
        // condition "x + y >= stack.back().second" suggests that y is
        // relatively larger, thereby making it a better candidate.
        while (!stack.empty() && x + y >= stack.back().second)
          stack.pop_back();
        if (stack.empty() || y > stack.back().first)
          stack.emplace_back(y, x + y);
      }
      const auto it = lower_bound(stack.begin(), stack.end(),
                                  pair<int, int>{minY, INT_MIN});
      ans[index] = it == stack.end() ? -1 : it->second;
    }

    return ans;
  }

 private:
  vector<Pair> getPairs(const vector<int>& nums1, const vector<int>& nums2) {
    vector<Pair> pairs;
    for (int i = 0; i < nums1.size(); ++i)
      pairs.push_back({nums1[i], nums2[i]});
    sort(pairs.begin(), pairs.end(),
         [](const Pair& a, const Pair& b) { return a.x > b.x; });
    return pairs;
  }

  vector<IndexAndQuery> getIndexAndQueries(const vector<vector<int>>& queries) {
    vector<IndexAndQuery> indexAndQueries;
    for (int i = 0; i < queries.size(); ++i)
      indexAndQueries.push_back(IndexAndQuery{
          .index = i,
          .minX = queries[i][0],
          .minY = queries[i][1],
      });
    sort(indexAndQueries.begin(), indexAndQueries.end(),
         [](const IndexAndQuery& a, const IndexAndQuery& b) {
      return a.minX > b.minX;
    });
    return indexAndQueries;
  }
};
