class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        set<vector<int>> s;
        
        vector<vector<int>> iQueries;
        for(int i=0; i < queries.size(); i++) {
            iQueries.push_back({queries[i], i});
        }
        
        sort(intervals.begin(), intervals.end());
        sort(iQueries.begin(), iQueries.end());
        
        vector<int> result(queries.size(), -1);
        
        int i = 0, len = intervals.size();
        
        for(auto& iq: iQueries) {
            int q = iq[0];
            int idx = iq[1];
            
            while( i < len && intervals[i][0] <= q) {
                s.insert({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while( !s.empty() ) {
                auto it = s.begin();
                if ( (*it)[1] >= q ) break;
                s.erase(s.begin());
            }
            if ( !s.empty() ) {
                auto it = s.begin();
                result[idx] = (*it)[0];
            }
        }
        
        return result;
    }
};