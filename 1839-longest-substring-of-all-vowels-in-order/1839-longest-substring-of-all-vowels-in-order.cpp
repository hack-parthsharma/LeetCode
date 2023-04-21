class Solution {
private:
    enum Vowels{
        A = 0,
        E = 1,
        I = 2,
        O = 3,
        U = 4,
        INVAILD = -1,
    };
    
    Vowels isVowels(char c) {
        switch(c) {
            case 'a' : return A;
            case 'e' : return E;
            case 'i' : return I;
            case 'o' : return O;
            case 'u' : return U;
        }
        return INVAILD;
    }
public:
    int longestBeautifulSubstring(string word) {
        word += 'a';
        int len = 0;

for(int i=0; i<word.size(); i++) {
            if (word[i] != 'a') continue;
            
            int prevIdx = A;
            int j=i;
            for(; j<word.size(); j++) {
                int currIdx = isVowels(word[j]);
                // the current char is same as before.
                if ( currIdx == prevIdx || currIdx == INVAILD) continue;
                // the current char is the next vowel.
                if ( currIdx == prevIdx + 1) { prevIdx++; continue;}
                // the current char is not in order, 
                // and the previous char is the final vowel.
                if ( prevIdx == U ){
                    len = max(len, j-i);
                }
                break;
            }
            i = j-1;
        }
        return len;
        
    }
};