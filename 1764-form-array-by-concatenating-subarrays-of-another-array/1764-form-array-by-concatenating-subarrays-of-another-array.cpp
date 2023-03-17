class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        
        //constructing an length array
        //  lens[0] = len(groups[0]) + len(groups[1]) + ... len(groups[n])
        //  lens[1] = len(groups[1]) + len(groups[2]) + ... len(groups[n])
        //  lens[2] = len(groups[2]) + len(groups[3]) + ... len(groups[n])
        //  lens[n] = len(groups[n])
        //so that, we can quickly know whether there still has enough room to match rest groups
        vector<int> lens(groups.size());
        int total_len=0;
        for(int i=groups.size()-1; i >=0; i--) {
            total_len += groups[i].size();
            lens[i] = total_len;
        }
        
        // index i - loop for groups[]
        // index j - loop for nums[]
        int i = 0, j = 0; 
        while ( i < groups.size() && j < nums.size() ) {
            //if the rest room is not enought to match, return false;
            if (nums.size() - j < lens[i]) return false;
            
            //if the first char is not matched, check the next.
            if ( nums[j] != groups[i][0]) {
                j++;
                continue;
            }
            
            //if the first char is matched, then check the groups[i]
            bool match = true;
            for(int k=0; k<groups[i].size(); k++) {
                if ( nums[j+k] != groups[i][k]) {
                    match=false;
                    break;
                }
            }
            
            // if the groups[i] is matched, then go to next group
            if (match) {
                j += groups[i].size();
                i++;
            }else{
                j++;  
            }
        }
        
        return i == groups.size();
    }
};