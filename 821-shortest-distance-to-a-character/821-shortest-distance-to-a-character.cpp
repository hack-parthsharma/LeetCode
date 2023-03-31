class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> res;
        int prev_char = -s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c)
                prev_char = i;
            res.push_back(i - prev_char);
        }

        for (int i = prev_char; i >= 0; i--) {
            if (s[i] == c)
                prev_char = i;
            res[i] = min(res[i], prev_char - i);
        }
        return res;
    }
};
