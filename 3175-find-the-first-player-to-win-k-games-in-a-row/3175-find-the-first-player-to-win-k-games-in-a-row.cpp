class Solution {
 public:
  int findWinningPlayer(vector<int>& skills, int k) {
    int ans = 0;
    int wins = 0;

    for (int i = 1; i < skills.size() && wins < k; ++i)
      if (skills[i] > skills[ans]) {
        ans = i;
        wins = 1;
      } else {
        ++wins;
      }

    return ans;
  }
};