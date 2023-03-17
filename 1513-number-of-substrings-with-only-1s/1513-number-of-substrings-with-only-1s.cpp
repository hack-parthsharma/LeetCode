class Solution {
public:
    // 11 - 1+2
    // 111 - 1+2+3
    // 1111 - 1+2+3+4
    // 11111 - 1+2+3+4+5
    // so, we just simply find the length of continuous '1',
    // then, the answer it len*(len+1)/2
    int numSub(string s) {
       long long len=0;
       long long result=0;
        for (auto c : s) {
            if (c=='1') {
                len++;
                continue;
            }
            if (len > 0){
                result += len*(len+1)/2;
                len = 0;
            }
        }

        result += len*(len+1)/2;
        return result % 1000000007 ;
    }
};