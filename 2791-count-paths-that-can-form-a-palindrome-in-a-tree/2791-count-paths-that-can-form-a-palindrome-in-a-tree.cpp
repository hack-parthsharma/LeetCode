class Solution {
 public:
  long long countPalindromePaths(vector<int>& parent, string s) {
    vector<vector<int>> tree(parent.size());

    for (int i = 1; i < parent.size(); ++i)
      tree[parent[i]].push_back(i);

    return dfs(tree, 0, 0, s, {{0, 1}});
  }

 private:
  long long dfs(const vector<vector<int>>& tree, int u, int mask,
                const string& s, unordered_map<int, int>&& maskToCount) {
    long long res = 0;
    if (u > 0) {
      mask ^= 1 << (s[u] - 'a');
      for (int i = 0; i < 26; ++i)
        if (const auto it = maskToCount.find(mask ^ (1 << i));
            it != maskToCount.cend())
          res += it->second;
      res += maskToCount[mask ^ 0]++;
    }
    for (const int v : tree[u])
      res += dfs(tree, v, mask, s, move(maskToCount));
    return res;
  }
};
