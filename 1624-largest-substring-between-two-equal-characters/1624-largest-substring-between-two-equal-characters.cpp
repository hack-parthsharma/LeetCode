class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        for (int i = 'a'; i <= 'z'; ++i) {
            int first = -1, last = -1;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] != i) continue;
                if (first == -1) first = j;
                last = j;
            }
            ans = max(ans, last - first - 1);
        }
        return ans;
    }
};