class Solution {
private:
    bool isWord(char ch) {
        return (ch >='a' && ch <= 'z' ) || ( ch >='A' && ch <= 'Z');
    }
    bool isSpace(char ch) {
        return (ch == ' ');
    }
    void split(string& s, vector<string>& words) {
        s += ' ';
        int start=0, end=0;
        while(start < s.size()) {
            while(isSpace(s[start])) start++;
            end = start;
            while(!isSpace(s[end])) end++;
            words.push_back(s.substr(start, end-start));
            start = end + 1;
        }
    }
    void print(vector<string>& v) {
        cout << "[";
        for(int i=0; i<v.size()-1; i++) {
            cout << v[i] << ", ";
        }
        cout << v[v.size()-1] << "]" << endl;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        string& longstr = sentence1.size() >= sentence2.size() ? sentence1 : sentence2;
        string& shortstr = sentence1.size() < sentence2.size() ? sentence1 : sentence2;
        if ( longstr == shortstr ) return true;
        
        vector<string> words1, words2;
        split(shortstr, words1);
        split(longstr, words2);
        //print(words1); print(words2);
        
        int left=0, right=words1.size()-1;
        while(left< words1.size() && words1[left] == words2[left]) left++;
        
        int delta = words2.size() - words1.size();
        while(right>=left && words1[right] == words2[delta+right]) right--;
        //cout << left << ":" << right << ":" << delta << endl;
        
        return left > right;
    }
};