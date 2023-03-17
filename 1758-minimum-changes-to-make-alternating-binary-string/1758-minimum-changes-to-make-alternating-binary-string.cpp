class Solution {
public:
    int minOperations(string s) {
        int start_with_zero = 0;
        int start_with_one = 0;
        for (int i=0; i<s.size(); i++){
            if (i % 2 == 0) {
                s[i] == '1' ? start_with_zero++ : start_with_one++;
            }else{
                s[i] == '0' ? start_with_zero++ : start_with_one++;
            }
        }
        return std::min(start_with_zero, start_with_one);
    }
};