class Solution {
public:
    int maxRepeating(string sequence, string word) {
        string f = word;
        int k = 1;
        for (; sequence.find(f) != string::npos; ++k, f += word);
        return k - 1;
    }
};