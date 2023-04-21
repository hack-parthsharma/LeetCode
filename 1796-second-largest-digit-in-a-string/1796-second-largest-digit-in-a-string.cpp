class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (auto& c : s){
            if (c >='0' && c<='9') {
                int n = c - '0';
                if ( n > first) {
                    second = first;
                    first = n;
                }else if (n < first && n > second) {
                    second = n;
                }
            }
        }
        return second;
    }
};