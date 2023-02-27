class Solution {
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        const int MAX_NUM = 100001;
        int cnt[MAX_NUM] = {0};
        int maxn = 0;
        for(auto& n : nums) {
            cnt[n]++;
            maxn = max(maxn, n);
        }
        
        vector<vector<int>> stats;
        for(int i=1; i<MAX_NUM; i++) {
            if (cnt[i] > 0) {
                stats.push_back({i, cnt[i]});
            }
            cnt[i] += cnt[i-1];
        }
        const int MOD = 1e9+7;
        int result = 0;
        for(int i=0; i < stats.size(); i++) {
            int n = stats[i][0];
            int c = stats[i][1];

            for(int x=2; x <= maxn/n+1; x++) {
                int pre = (x-1) * n - 1; 
                int cur = min( x * n - 1, MAX_NUM-1);
                result = (result + (cnt[cur] - cnt[pre]) * long(x-1) * c) % MOD;      
            }
        }
        return result;
    }
};