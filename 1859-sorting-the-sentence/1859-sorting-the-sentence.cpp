class Solution {
public:
    string sortSentence(string s) {
        const int MAX_WORDS = 9;
        string ss[MAX_WORDS];
        string word;
        for(int i=0; i<s.size(); i++){
            char ch = s[i];
            
            if (ch >='0' && ch <='9'){
                ss[ch-'0'-1] = word;
                word = "";
            }else if (ch != ' ') {
                word += ch;
            }
        }
        
        for(int i=1; i < MAX_WORDS; i++){
            if (ss[i].size() <= 0 ) continue;
            ss[0] = ss[0] +" " + ss[i];
        }
        return ss[0];
    }
};
