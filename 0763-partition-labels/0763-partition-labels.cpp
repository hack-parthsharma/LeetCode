class Solution {
 public:
  vector<int> partitionLabels(string s) {
    vector<int> ans;
    vector<int> rightmost(128);
    for (int i = 0; i < s.length(); ++i)
      rightmost[s[i]] = i;
    int l = 0;  
    int r = 0;  
    for (int i = 0; i < s.length(); ++i) {
      r = max(r, rightmost[s[i]]);
      if (r == i) {
        ans.push_back(i - l + 1);
        l = i + 1;
      }
    }
    return ans;
  }
};
