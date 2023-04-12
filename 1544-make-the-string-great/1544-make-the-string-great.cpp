class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (char c : s) {
            if (ans.size() && ans.back() != c && toupper(ans.back()) == toupper(c)) ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};