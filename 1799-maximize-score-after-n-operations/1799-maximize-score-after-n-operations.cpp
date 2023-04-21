class Solution {
private:
    // Euclidean algorithm
    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    int gcd(int a, int b) {
        while(a != b) {
            if(a > b) a = a - b;
            else b = b - a;
        }
        return a;
    }
    unordered_map<int, int> cache;
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> pair_gcd(n, vector<int>(n, 0) );
        
        for (int i=0; i< n - 1; i++) {
            for (int j=i+1; j < n; j++ ) {
                pair_gcd[i][j] = gcd(nums[i], nums[j]);
            }
        }
        
        // used_mark[] - remember the num has been used.
        return maxScore(pair_gcd, 0, n, n/2);
    }
    
    int maxScore(vector<vector<int>>& pair_gcd, int mask, int n, int step) {
        if (cache.find(mask) != cache.end()) {
            return cache[mask];
        }
        int m = 0;
        
        for (int i=0; i< n - 1; i++) {
            if ( (1<<i) & mask ) continue;
            for (int j=i+1; j < n; j++ ) {
                if ((1<<j) & mask) continue;
                if (step == 1) {
                    return pair_gcd[i][j];
                }
                
                m = max(m, step * pair_gcd[i][j] + 
                        maxScore(pair_gcd, mask | (1<<i) | (1<<j), n, step-1));
                
            }
        }
        
        cache[mask] = m;
        return m;
    }
};