class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int len = min(len1, len2);
        
        string result;
        for (int i=0; i<len; i++) {
            result += word1[i];
            result += word2[i];
        }
        
        if (len1 > len) result += word1.substr(len, len1 - len );
        if (len2 > len) result += word2.substr(len, len2 - len );
        return result;
    }
};