class Solution {
private:
    map<char, char>  eq_map; // the table store the equivalent relationship
    void init() {
        for (char ch='a'; ch<='z'; ch++) {
            eq_map[ch] = ch;
        }
    }
public:
    Solution() {
        init();
    }
    
    // find the tail node, 
    // if a == b == c == d, find(a) would return d;
    //                      find(b) would return d;
    char find(char ch) {
        while(ch != eq_map[ch]) {
            ch = eq_map[ch];
        }
        return ch;
    }
    
    //join x equivalent chain with y equivalent chain
    void join(char x, char y) {
        char tx = find(x);
        char ty = find(y);
        if (tx != ty) { 
            eq_map[tx] = ty;
        }
    }

    bool equationsPossible(vector<string>& equations) {
        for (auto e : equations ) {
            if (e[1] == '=' && e[0] != e[3]) { // equal
                join(e[0], e[3]);
            }
        }
        for (auto e : equations) {
            if (e[1] == '!' && (e[0] == e[3] || find(e[0]) == find(e[3]) ) ) { 
                return false;
            }
        }
        return true;
    }
};
