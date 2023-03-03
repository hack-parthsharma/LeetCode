class Solution {

public:
    int longestPalindrome(string word1, string word2) {
        
        string s = word1 + word2;
        int n = s.size(); 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        int result = 0; 
        for (int start = n-1; start>=0; start--) {
            for (int end = start ; end < n ; end++) {
                if (start == end) {
                    dp[start][end] = 1;
                    continue;
                }
                if (s[start] == s[end]) {
                    dp[start][end] = dp[start+1][end-1] + 2;
                    // <-----------  different -----------> 
                    //only consider when `start` and `end` in different string.
                    if (start < word1.size() && end >= word1.size()){
                        result = max(result, dp[start][end]);
                    }
                    // <-----------  different -----------> 
                }else{
                     dp[start][end] = max (dp[start+1][end], dp[start][end-1]);
                }
                
            }
        }  
        return result;
    }
};