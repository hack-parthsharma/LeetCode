class Solution {
public:
    string modifyString(string s) {
        int i = 0, N = s.size();
        while (i < N) {
            while (i < N && s[i] != '?') ++i;
            int c = (i == 0 ? 0 : (s[i - 1] - 'a' + 1) % 26);
            while (i < N && s[i] == '?') {
                s[i] = c + 'a';
                c = (c + 1) % 26;
                if (i + 1 < N && s[i + 1] != '?' && s[i] == s[i + 1]) s[i] = c + 'a';
            }
        }
        return s;
    }
};