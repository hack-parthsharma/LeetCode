class Solution {
private:
    //GCD -  greatest common divisor 
    int greatestCommonDivisor (int a, int b) {
        if(b) while((a %= b) && (b %= a));
        return a + b;
    }
    //LCM - least common multiple 
    int leastCommonMultiple(int a, int b) {
        return a * b / greatestCommonDivisor(a, b);
    }
public:
    int mirrorReflection(int p, int q) {
        int lcm = leastCommonMultiple(p, q);
        if (lcm % (2*p) == 0 ) return 0;
        
        int nq = lcm / q; 
        
        if (nq % 2 == 0 ) return 2;
        return 1;
    }
};
