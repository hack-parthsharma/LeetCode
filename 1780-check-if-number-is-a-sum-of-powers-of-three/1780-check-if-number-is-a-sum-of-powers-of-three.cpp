class Solution {
public:
    bool checkPowersOfThree(int n) {
        return checkPowersOfThree_Base3(n);
        return checkPowersOfThree_DFS(n, 1);
    }
    
    bool checkPowersOfThree_DFS(int n, int p) { 
        if (n == p ) return true;
        if (n < p ) return false;
        
        return (checkPowersOfThree_DFS(n-p, p*3) || checkPowersOfThree_DFS(n, p*3));
    }
    /*
     * convert base-10 number to base-3 number
     * for example: 
     *    12 ->  110 = 1*3^2 + 1*3^1 + 0*3^0
     *    16 ->  121 = 1*3^2 + 2*3^1 + 1*3^0
     *    21 ->  210 = 2*3^2 + 1*3^1 + 0*3^0
     *    
     *    91 -> 1011 = 1*3^4 + 0*3^2 + 1*3^1 + 1*3^0
     *    
     * so, we can see, if a base3 number only has 1 or 0, then it's valid.
     * if `2` appeas, then it's invalid.
     */
    bool checkPowersOfThree_Base3(int n) { 
        for (; n>0; n/=3) {
            if (n%3 == 2) return false;
        }
        return true;
    }
};