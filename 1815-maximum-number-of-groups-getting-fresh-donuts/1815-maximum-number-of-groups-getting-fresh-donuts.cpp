class Solution {
public:
    int maxHappyGroups(int batchSize, vector<int>& groups) {
        vector<int> reminder(batchSize, 0);
        for(auto& g : groups) {
            reminder[g % batchSize]++;
        }
        
        // greedy for reminder is zero and two groups reminder is zero.
        // for example: batchSize = 3, groups = [1,2,3,4,5,6]
        // then we will find: (3) (6) (1,5) (2,4) 
        
        // greedy for one group
        int result = reminder[0]; 
        //greedy for two groups
        for (int i=1; i<=batchSize/2; i++){
            if (reminder[i] == 0 || reminder[batchSize-i] == 0 ) continue;
            
            int m = (i == batchSize-i) ? 
                reminder[i]/2 :
                min(reminder[i], reminder[batchSize-i]);
            
            reminder[i] -= m;
            reminder[batchSize-i] -= m;
            result += m;
        }
        
        map<vector<int>, int> cache;
        //DFS for the rest groups
        result += dfs(reminder, batchSize, 0, cache);
        return result;
    }
    
    int dfs(vector<int>& reminder, int batchSize, int sum, map<vector<int>, int>& cache) {
        if (cache.find(reminder) != cache.end()) return cache[reminder];
        int ret = 0; 
        int bonus = sum == 0 ? 1: 0;
        for(int i=1; i<batchSize; i++) {
            if (reminder[i] <= 0)  continue;
            reminder[i]--;
            ret = max(ret, bonus + dfs(reminder, batchSize, (sum + i) % batchSize, cache));
            reminder[i]++;
        }
        cache[reminder] = ret;
        return ret;
    }
};
