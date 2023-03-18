class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int start = n-1; start>=0; start--) {
            for (int end = start ; end < n ; end++) {
                if (start == end) {
                    dp[start][end] = 1;
                    continue;
                }
                if (s[start] == s[end]) {
                    dp[start][end] = dp[start+1][end-1] + 2;
                }else{
                     dp[start][end] = max (dp[start+1][end], dp[start][end-1]);
                }
                
            }
        }
        return dp[0][n-1];
    }
};