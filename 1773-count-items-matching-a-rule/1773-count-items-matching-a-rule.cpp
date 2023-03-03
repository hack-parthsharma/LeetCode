class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int idx;
        switch(ruleKey[0]) {
            case 't': idx = 0; break;
            case 'c': idx = 1; break;
            case 'n': idx = 2; break;
            default: return 0;
        }
        
        int cnt = 0;
        for (auto& item : items) {
            if (item[idx] == ruleValue) cnt++;
        }
        return cnt;
    }
};