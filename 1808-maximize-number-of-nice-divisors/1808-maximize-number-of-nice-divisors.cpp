const int mod = 1000000007;

class Solution {
public:
    int maxNiceDivisors(int primeFactors) {
        return maxNiceDivisors_03(primeFactors);
        return maxNiceDivisors_02(primeFactors); //TLE
        return maxNiceDivisors_01(primeFactors); //TLE
    }
    
    int maxNiceDivisors_01(int primeFactors) {
        int result = 1;
        while ( primeFactors > 4 ) {
            primeFactors -= 3;
            result = (result * 3l) % mod;
        }
        result = (result * (long)primeFactors) % mod;
        return result;
    }
    
    int maxNiceDivisors_02(int primeFactors) {
        if (primeFactors <= 4 ) return primeFactors;
        int result = 1;
        for (int i = 4; i > 0; i-- ){
            if ((primeFactors - i) % 3 == 0){ 
                result = i;
                primeFactors -= i;
                // now, `primeFactors` is 3 times - 3X
                // we need convert 3X to 3^X
                for (int x = primeFactors/3; x > 0; x-- ) {
                    result = (result * 3l) % mod;
                }
                break;
            }
        }
        return result;
    }
    
    int pow3(int x) {
        long  result = 1;
        long  factor = 3;
        while(x > 0) {
            if (x & 1) {
                result = (result * factor) % mod;
                
            }
            factor *= factor;
            factor %= mod;
            x /= 2;
        }
        return result % mod;
    }
    
    int maxNiceDivisors_03(int primeFactors) {
        
        if (primeFactors <= 4 ) return primeFactors;
        int result = 1;
        for (int i = 4; i > 0; i-- ){
            if ((primeFactors - i) % 3 == 0){ 
                primeFactors -= i;
                // now, `primeFactors` is 3 times - 3X
                // we need convert 3X to 3^X
                int x = primeFactors / 3;
                result = (long(i) * pow3(x)) % mod;
                break;
            }
        }
        return result;
    }
};