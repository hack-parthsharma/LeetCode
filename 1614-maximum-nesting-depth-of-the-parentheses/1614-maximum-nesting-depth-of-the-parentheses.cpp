class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, left = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != '(' && s[i] != ')') continue;
            if (s[i] == '(') ++left;
            else --left;
            ans = max(ans, left);
        }
        return ans;
    }
};