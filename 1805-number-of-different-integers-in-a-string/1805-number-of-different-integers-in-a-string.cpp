class Solution {
private:
    bool isNumber(char ch) {
        return (ch >='0' && ch <='9');
    }
    
public:
    int numDifferentIntegers(string word) {
        word.push_back('z'); // add a char for edge case.
        bool intStart = false; // a stat for control 
        int start = 0, len = 0;
        unordered_map<string, bool> stat;
        for(int i=0; i<word.size(); i++) {
            if (!isNumber(word[i]) ) {
                if (intStart) {
                    while(word[start]=='0') {
                        start++, len--;
                    }
                    stat[word.substr(start, len)] = true;
                    intStart=false; 
                }
                continue;
            }
            
            if (intStart == false) {
                intStart = true;
                start = i;
                len = 1;
            }else {
                len++;
            }
        }
        return stat.size();           
    }
};