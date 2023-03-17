class Solution {
public:
    int countHomogenous(string s) {
        long long result = 0;
        char current = '\0';
        long long len = 0;
        for(int i = 0; i < s.size() ; i++) {
            if (current != s[i] ){
                //sum from 1 to len
                result += len * (len+1)/2;
                current = s[i];
                len = 1;
            }else{
                len++;
            }
        }
        //the rest string
        result += len * (len+1)/2;
        return result % 1000000007;
    }
};