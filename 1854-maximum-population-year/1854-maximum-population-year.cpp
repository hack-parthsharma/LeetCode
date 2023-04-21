class Solution {

public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<vector<int>> year;
        
        for(auto& log : logs) {
            year.push_back({log[0], 1});
            year.push_back({log[1], -1});
        }
        sort(year.begin(), year.end());
        
        int x = year[0][0];
        int cnt = 0, max_cnt = 0;
        for(int i=0; i< year.size(); i++) {
            cnt += year[i][1];
            if (max_cnt < cnt) {
                max_cnt = cnt;
                x = year[i][0];
            }
        }
        return x;
    }
};