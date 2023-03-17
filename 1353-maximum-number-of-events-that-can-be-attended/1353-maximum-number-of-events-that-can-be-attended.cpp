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


    //union find
    int find(int x, vector<int>& f) {
        if(f[x] == x) {
            return x;
        } else {
            return f[x] = find(f[x], f);
        }
    }
    void print(vector<vector<int>>& events){
        cout << "[" ;
        for(auto e: events) {
            cout << "[" << e[0] << "," << e[1] << "]," ;
        }
        cout << "]" << endl;
    }
public:
    int maxEvents(vector<vector<int>>& events) {
        return maxEvents_priority_queue(events);//332ms
        return maxEvents_union_find(events); // 336ms
    }

    int maxEvents_priority_queue(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), comp_start);
        //print(events);

        int start = events[0][0];
        int end = 0;
        for(auto& e:events){
            end = max(end, e[1]);
        }

        int result = 0;
        int i = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int day = start; day <= end; day++) {
            while (i<events.size() && events[i][0]==day) {
                pq.push(events[i][1]); //push the ending day
                i++;
            }
            //remove out-of-date event
            while(!pq.empty() && pq.top() < day)  {
                pq.pop();
            }

            //if there still has event, then choose current day.
            if (!pq.empty()){
                pq.pop();
                result++;
            }

            //no more date need to process
            if (pq.empty() && i >= events.size()) break;
        }
        return result;
    }

    int maxEvents_union_find(vector<vector<int>>& events) {
        std::sort(events.begin(), events.end(), comp_end);


        int end = events[events.size()-1][1];
        int start = end;
        for(auto& e:events){
            start = min(start, e[0]);
        }

        vector<int> dict;
        for (int i=0; i<=end-start+1; i++){
            dict.push_back(i);
        }

        int result = 0;

        for(auto& e : events) {

            int x = find(e[0]-start, dict);
            if ( x <= e[1]-start ){
                result++;
                dict[x] = find(x+1, dict);
            }
        }

        return result;
    }
};