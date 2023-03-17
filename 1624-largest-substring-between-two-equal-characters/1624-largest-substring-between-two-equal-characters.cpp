class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int pos[26]={0};
        
        int longest = -1 ;
        for (int i=0; i<s.size(); i++){
            int idx = s[i] -'a';
            if (pos[idx] == 0)  pos[idx] = i + 1; 
            else longest = max(longest, i - pos[idx]);
        }
        
        return longest;
    }
};