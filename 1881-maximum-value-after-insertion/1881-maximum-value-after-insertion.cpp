class Solution {
public:
    string maxValue(string n, int x) {
        bool neg = false;
        if (n[0] == '-') neg = true;
        
        int i;
        
        for( i=neg?1:0; i<n.size(); i++){
            if (neg == true) {
                if ( n[i]-'0' > x) break;
            }else{ 
                if (n[i]-'0' < x) break; 
            }
        }
     
        n.insert(n.begin()+i, x+'0');
        return n;
    }
};
