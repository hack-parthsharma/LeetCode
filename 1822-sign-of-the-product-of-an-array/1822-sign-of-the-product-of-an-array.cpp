class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negtive=0;
        for(auto& n : nums) {
            if (n==0) return 0;
            if (n < 0) negtive++;
        }
        return negtive % 2 == 0 ? 1 : -1;
    }
};