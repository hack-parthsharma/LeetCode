class Solution {
public:
    // This problem could transfer to check two array has exactly same numbers
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       
       
        int len1 = target.size();
        int len2 = arr.size();
        if (len1 != len2) return false;
        if (len1 == 0) return true;
        
        unordered_map<int, int> stat;
        for (int i=0; i<len1; i++) {
            stat[target[i]]++;
            stat[arr[i]]--;
        }
        
        for (auto& s:stat) {
            if (s.second !=0 ) return false;
        }
        return true;
    }
    
};