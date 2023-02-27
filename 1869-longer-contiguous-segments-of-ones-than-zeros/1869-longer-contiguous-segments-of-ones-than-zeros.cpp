class Solution {
public:
    bool checkZeroOnes(string s) {
        int zeros = 0;
        int ones = 0;
        int i = 0;
        while (i < s.size()) {
            if(s[i] == '0') {
                int cnt = 0;
                for (;s[i] == '0' && i < s.size(); i++) cnt++;
                zeros = max(zeros, cnt);
            }else {
                int cnt = 0;
                for (;s[i] == '1'&& i < s.size(); i++) cnt++;
                ones = max(ones, cnt);
            }
        }
        return ones > zeros;
    }
};
