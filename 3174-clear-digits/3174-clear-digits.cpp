class Solution {
 public:
  string clearDigits(string s) {
    string ans;

    for (const char c : s)
      if (isdigit(c))
        ans.pop_back();
      else
        ans += c;

    return ans;
  }
};