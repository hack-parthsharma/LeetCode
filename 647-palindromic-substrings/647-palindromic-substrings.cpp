class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        if (len<=1) return len;
        
        vector< vector<bool> > dp(len, vector<bool>(len, false));
        
        int cnt = 0;
        for( int i=len-1; i>=0; i--) {
            for (int j=i; j<=len-1; j++) {              
                if ( i == j  || ( s[i] == s[j] && ( j-i<2 || dp[i+1][j-1]) ) ) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
                                  
        return cnt;       
        
    }
};