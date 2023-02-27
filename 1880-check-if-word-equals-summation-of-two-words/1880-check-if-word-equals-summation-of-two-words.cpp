class Solution {
public:
    int strToInt(string& str) {
        int n = 0;
        for(auto& c :str) {
            n = n*10 + c - 'a';
        }
        return n;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return strToInt(firstWord) + strToInt(secondWord) == strToInt(targetWord);
    }
};
