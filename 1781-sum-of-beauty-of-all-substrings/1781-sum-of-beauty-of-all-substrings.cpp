class Solution {
private:
    int beauty(string& s, int start, int end) {
        int stat[26] = {0};
        for (int i=start; i<=end; i++){
            stat[s[i]-'a']++;
        }
        int max = INT_MIN, min = INT_MAX; 
        for (auto s: stat) {
            if (s == 0 ) continue;
            max = s > max ? s : max;
            min = s < min ? s : min;
        }
        return max - min;
    }
public:
    int beautySum(string s) {
        return beautySum02(s);
        return beautySum01(s);
    }
    
    int beautySum01(string& s) {
        int sum = 0; 
        for (int i=0; i<s.size()-1; i++) {
            for (int j=i+1; j<s.size(); j++) {
                sum += beauty(s, i, j);
            }
        }
        return sum;
    }
    
    //same as beautySum01(), but optimazed slightly
    int beautySum02(string& s) {
        int sum = 0; 
        for (int i=0; i<s.size()-1; i++) {
            int stat[26] = {0};
            for (int j=i; j<s.size(); j++) {
                stat[s[j]-'a']++;
                int max = INT_MIN, min = INT_MAX; 
                for (auto& n: stat) {
                    if (n <= 0 ) continue; 
                    max = n > max ? n : max;
                    min = n < min ? n : min;
                }
                //cout << s.substr(i, j-i+1)  << " --> "<< max << ":" << min << endl;
                sum += (max - min);
            }
        }
        return sum;
    }
};

