class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> stat;
        for(int i = 0; i < nums.size(); i++) {
            for ( int j = i+1; j < nums.size(); j++) {
                stat[nums[i]*nums[j]]++;
            }
        }
        
        int result = 0;
        for ( auto [n, cnt] : stat) {
            if (cnt > 1) result += cnt*2 * (cnt-1)*2;
        }
        return result;
    }
};