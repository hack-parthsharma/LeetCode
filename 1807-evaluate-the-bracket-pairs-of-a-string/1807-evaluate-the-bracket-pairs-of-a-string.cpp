class Solution {
private:
    bool isBracket(char c) {
        return c=='(' || c == ')';
    }
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> dict;
        for(auto& k : knowledge) {
            dict[k[0]] = k[1];
        }
        
        string result;
        string key;
        bool meetLeftBracket = false;
        for(auto& c : s) {
           
            if (c == '(') {
                meetLeftBracket = true;
            } else if (c == ')') {
                meetLeftBracket = false;
                //cout << key << endl;
                if (dict.find(key) != dict.end()) {
                    result += dict[key];
                }else {
                    result += '?';
                }
                key = "";
            } else {
                if (meetLeftBracket) {
                    key += c;
                }else{
                    result +=c;
                }
            }
        }
        
        return result;
    }
};