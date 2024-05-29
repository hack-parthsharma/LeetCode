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

    // All 1s will become 0s and be popped by 1 step.
    // All 0s will become 1s and be popped by 2 step (add 1 then divide by 2).
    for (const char c : s)
      ans += c == '1' ? 1 : 2;

    return ans;
  }
};
