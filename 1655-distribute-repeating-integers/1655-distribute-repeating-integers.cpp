class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& q) {
        int N = q.size();
        unordered_map<int, int> mp;
        for (auto n : nums) {
            mp[n]++;
        }
        vector<int> freq;
        for (auto p : mp) {
            freq.push_back(p.second);
        }
        int LF = freq.size();
        vector<int> sq(1<<N); // sum of quantity
        for (int i=0; i<(1<<N); i++) {
            for (int j=0; j<N; j++) {
                if (i & (1<<j)) {
                    sq[i] += q[j];
                }
            }
        }
        vector<vector<bool>> dp(LF+1, vector<bool>(1<<N));
        dp[0][0] = true;
        for (int i=1; i<=LF; i++) {
            for (int j=0; j<(1<<N); j++) {
                if (!dp[i-1][j]) continue;
                for (int k=0; k<(1<<N); k++) {
                    if (k & j) continue;
                    if (sq[k] > freq[i-1]) continue;
                    dp[i][k|j] = true;
                }
            }
        }
        return dp[LF][(1<<N)-1];
  }};