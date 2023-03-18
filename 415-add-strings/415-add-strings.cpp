class Solution {
public:
    string addStrings(string num1, string num2) {
        string& longstr  = ( num1.size() >= num2.size() ? num1 : num2 );
        string& shortstr = ( num1.size() <  num2.size() ? num1 : num2 );
        
        int longlen = longstr.size();
        int shortlen = shortstr.size();
        
        char carry = 0;
        int i, j;
        
        string result;
        for (i = longlen-1, j=shortlen-1; i>=0; i--, j--) {
            int add = 0;
            if (j>=0) {
                add = longstr[i] + shortstr[j] - 2 * '0' + carry;
            }else{
                add = longstr[i] - '0' + carry;
            }
            carry = add/10;
            result = char('0' + add % 10) + result;
        }
        
        if (carry) {
            result = '1' + result;
        }
        return result;
    }
};