class Solution {
public:
  int minSteps(string s, string t) {
    vector<int> count(26);
    for (const char c : s)
      ++count[c - 'a'];
    for (const char c : t)
      --count[c - 'a'];
    return accumulate(begin(count), end(count), 0,
                      [](int subtotal, int c) { return subtotal + abs(c); }) /
           2;
  }
};
