class Solution {
 public:
  string clearDigits(string s) {
    string ans;

    for (const char c : s)
      if (isdigit(c))
        // character is equivalent to deleting the closest non-digit character.
        ans.pop_back();
      else
        ans += c;

    return ans;
  }
};