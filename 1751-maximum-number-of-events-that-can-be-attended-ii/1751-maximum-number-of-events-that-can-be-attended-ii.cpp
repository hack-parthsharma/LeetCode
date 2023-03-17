class Solution {
private:
    static const bool comp_start(vector<int>& x, vector<int>& y) {
        if ( x[0] != y[0] ) return x[0] < y[0];
        return x[1] < y[1];
    }
    static const bool comp_end(vector<int>& x, vector<int>& y) {
        if ( x[1] != y[1] ) return x[1] < y[1];
        return x[0] < y[0];
    }
    void print(vector<vector<int>>& events){
        cout << "[" ;
        for(int i = 0; i<events.size(); i++) {
            cout << "["; 
            for (int j = 0; j < events[i].size(); j++) {
                cout << events[i][j] << (j == events[i].size() - 1 ? "":",") ;
            }
            cout <<  (i == events.size()-1 ? "]": "],") ;
        }

        cout << "]" << endl;
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        
        //Solution3 - DP
        std::sort(events.begin(), events.end(), comp_end);
        return maxValueDP(events, k); 
    
        std::sort(events.begin(), events.end(), comp_start);
        //Solution 2 - DFS with cache --> Time Limit Exceeded
        vector<vector<int>> cache(events.size()+1, vector<int>(k+1, -1));
        return maxValueDFS(events, 0, k, cache);
        
        //Solution 1 - DFS --> Time Limit Exceeded
        return maxValueDFS(events, 0, k); 
    }
    
    //binary search to find the first event which start day is greater than the `day`
    /* 
     * for (int i = low; i < events.size(); i++) {
     *   if ( events[i][0] > day ) break;
     * }
     */
    int findNextEvent(vector<vector<int>>& events, int low, int day) {

        int high = events.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if ( events[mid][0] <= day) {
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return ( events[low][0] > day ) ? low : low+1;
    }
    
    int maxValueDFS(vector<vector<int>>& events, int current, int k) {
        if (current >= events.size() || k == 0 ) return 0;
        
        // if we select the events[index], then find the next events
        int next = findNextEvent(events, current, events[current][1]);
        
        // we have two choice, attend the event or not
        int attend = events[current][2] + maxValueDFS(events, next, k-1);
        int skip = maxValueDFS(events, current + 1, k);
        
        return std::max(attend, skip);
    }
    
    int maxValueDFS(vector<vector<int>>& events, int current, int k, vector<vector<int>>& cache) {
        if (current >= events.size() || k == 0 ) return 0;
        
        //if find in cache, then return
        if (cache[current][k] != -1) return cache[current][k];
        
        // if we select the events[index], then find the next events
        int next = findNextEvent(events, current, events[current][1]);
        
        // we have two choice, attend the event or not
        int attend = events[current][2] + maxValueDFS(events, next, k-1);
        int skip = maxValueDFS(events, current + 1, k);
        
        return cache[current][k] =  std::max(attend, skip);
        
    }
    
    
    //binary search to find the nearest previous event which ending day is less than the `day`
    /* 
     * for (int i = high; i >= 0; i++) {
     *   if ( events[i][1] < day ) break;
     * }
     */
    int findPrevEvent(vector<vector<int>>& events, int high, int day) {
        int low = 0;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if ( events[mid][1] < day) {
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low - 1;
    }
    
    int maxValueDP(vector<vector<int>>& events, int k) {
        // for each event, find the previous nearest event which 
        // ending day is less than its starting day
        
        for (int i = 0; i < events.size(); i++) {
            events[i].push_back( findPrevEvent(events, i, events[i][0]));
        }
        //print(events);
        
        vector<vector<int>> dp(events.size(), vector<int>(k, 0));
        
        //---== initial the dp table ==---
        //if we only have first event
        for(int i = 0; i<k; i++) {
            dp[0][i] = events[0][2];
        }
        //if we only can attend one event.
        for (int i = 1; i < events.size(); i++) {
            dp[i][0] = max(dp[i-1][0], events[i][2]);
        }

        for (int times = 1; times<k; times++) {
            for (int current = 1; current < events.size(); current++) {
                
                int prev = events[current][3];
                
                int attend = (prev == -1) ? 
                        events[current][2]: // not found the previous event
                        dp[prev][times-1] + events[current][2]; //found previouse event
                
                int skip =  dp[current-1][times];
                
                dp[current][times] = max (attend, skip );
            
            }
            
        }
        //print (dp);
        return dp.back().back();
    }
};