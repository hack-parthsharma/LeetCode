class Solution {
public:
int maxScore(string s) {
int one = 0, zero = 0, ans = 0;
for (char c : s) one += c == '1';
for (int i = 0; i < s.size() - 1; ++i) {
char c  = s[i];
zero += c == '0';
            one -= c == '1';
            ans = max(ans, zero + one);
}
return ans;
}
};