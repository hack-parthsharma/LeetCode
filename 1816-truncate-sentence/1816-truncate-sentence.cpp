class Solution {
private:
    bool isAlpha(const char& ch) {
        return (ch >='a' && ch <='z') || (ch >= 'A' && ch <='Z') ;
    }
public:
    string truncateSentence(string s, int k) {
        s += ' '; //for edge case
        bool wordStart = false;
        int i=0;
        for (; i< s.size(); i++) {
            if (!wordStart && isAlpha(s[i])) {
                wordStart = true;
            }else if (wordStart && !isAlpha(s[i])) {
                if (--k <= 0) break;
                wordStart = false;
            }
        }
        return s.substr(0, i);
    }
};