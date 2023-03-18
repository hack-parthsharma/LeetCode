class Solution {
public:
    string strWithout3a3b(int A, int B) {

        string result;
        while (true){

            // if A == B, then just simpley repeat "ab" pattern;
            if (A == B) {
                for ( int i=0; i<A; i++ ) {
                    result += "ab";
                }
                break;
            }

            // if A+B less then 3 and A != B, which means A=1,2 && B=0 or A=0 && B=1,2
            if (A+B <3) {
                while  ( A-- > 0 ) result += 'a';
                while  ( B-- > 0 ) result += 'b';
                break;
            }

            // if A+B >=3 and A !=B

            // if A > B, then we need consume 'a' more than 'b'
            // So, only "aab" can be used.
            if ( A > B ) {
                result += "aab";
                A -= 2;
                B--;
                continue;
            }

            // if A > B, then we need consume 'b' more than 'a'
            // So, only "bba" can be used.
            if (B > A ){
                result += "bba";
                B-=2;
                A--;
                continue;
            }

        }

        return result;
    }
};