class Solution {
public:
    int countGoodSubstrings(string s) {
        char exist[26] = {0};
        
        int cnt = 0, c = 0;
        
        
        for (int i = 0; i<s.size(); i++){
            char ch = s[i] - 'a';
            
            if (i > 2) {
                char ch = s[i-3]-'a';
                exist[ch]--;
                if ( exist[ch] == 0 ) c--;
            }
            
            exist[ch]++;
            if (exist[ch] == 1 ) {
                c++;
            }
            
            if ( c == 3 ){
                cnt++;
            }
            
        }
        
        return cnt;
    }
};
