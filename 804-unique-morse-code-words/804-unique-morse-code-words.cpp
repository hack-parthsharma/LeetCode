class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        string MorseTable[26] = {".-","-...","-.-.","-..",".","..-.","--.",
                                 "....","..",".---","-.-",".-..","--","-.",
                                 "---",".--.","--.-",".-.","...","-","..-",
                                 "...-",".--","-..-","-.--","--.."};
        unordered_map<string, bool> transformations;
        for (auto word : words) {
            string morse;
            for (auto ch : word) {
                morse += MorseTable[ ch - 'a' ];
            }
            transformations[morse]=true;
        }
        return transformations.size();
    }
};