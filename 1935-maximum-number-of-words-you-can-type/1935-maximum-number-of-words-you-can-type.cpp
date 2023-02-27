class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<bool> borken(26, false);
        
        for (auto ch : brokenLetters) {
            borken[ch - 'a'] = true;
        }
        
        text += ' ';
        int cnt = 0;
        for (int i = 0; i < text.size(); i++ ) {
            if ( text[i] == ' ') continue;
            
            bool skip = false;
            for (; text[i] != ' '; i++ ) {
                if (borken[text[i] - 'a'] == true ) skip = true;
            }
            if ( !skip ) cnt++;
        }
        
        return cnt;
    }
};