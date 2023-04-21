class Solution {
private:
    int pos;
public:
    bool getNum(string& s, long target) {
        
        long n = 0;
        while(s[pos] == '0') pos++; 
        while(pos < s.size()){
            n = (n*10 + s[pos++] - '0') ;
            if (n == target) return true;
            if (n > target ) return false; // n is already greater than target
        }
        return target == n;
    }
    
    long firstNum(string& s, int len) {
        long n = 0;
        while(s[pos] == '0') pos++; 
        for(; pos< s.size() && len > 0; pos++, len--) {
            n = (n*10 + s[pos] - '0') ;
        }
        return n;  
    }
    
    bool splitString(string s) {
        pos = 0;
        long num;
        for (int len=1; len<= s.size()/2+1; len++) {
            pos = 0;
            num = firstNum(s, len); 
            if (pos >= s.size()) continue; // only have one number
            
            bool result = true;
            while( pos < s.size() ) {
                if (getNum(s, --num) == false){
                    result = false;
                    break;
                }
            }
            if (result) return true;
        }
        return false;
    }
};