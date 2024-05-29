class Solution {
 public:
  int numSteps(string s) {
    int ans = 0;

    while (s.back() == '0') {
      s.pop_back();
      ++ans;
}

    if (s == "1")
      return ans;

    ++ans;

    for (const char c : s)
      ans += c == '1' ? 1 : 2;

    return ans;
  }
};
