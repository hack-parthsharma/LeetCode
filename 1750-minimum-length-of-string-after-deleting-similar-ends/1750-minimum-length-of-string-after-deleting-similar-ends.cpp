class Solution {
public:
    int minimumLength(string s) {
        char ch; 
        int left=0, right=s.size()-1;
        
        while(left < right) {
            ch = s[left];
            if (s[right] != ch) break;
            
            while (s[left] == ch) left++;
    
            if (left >= right ) return 0;
            while (s[right] == ch) right--;
        }
        
        return right - left + 1;
        
    }
};
