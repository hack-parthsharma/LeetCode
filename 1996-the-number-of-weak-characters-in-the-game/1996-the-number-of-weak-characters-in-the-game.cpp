class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>>& properties) {
    // Sort properties by attack descendingly, then by defense ascendingly
    sort(begin(properties), end(properties),
         [](const vector<int>& a, const vector<int>& b) {
      return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });

    int ans = 0;
    int maxDefense = 0;

    for (const vector<int>& property : properties) {
      const int defense = property[1];
      if (defense < maxDefense)
        ++ans;
      maxDefense = max(maxDefense, defense);
    }

    return ans;
  }
};
