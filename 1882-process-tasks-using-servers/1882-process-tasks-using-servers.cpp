class Solution {
private:
    template<class T>
    void print(T  q) {
        cout << "[";
        while(!q.empty()) {
            auto& p = q.top(); 
            cout << "[" << p.first << ","<< p.second << "]";
            q.pop();
        }
        cout << "]" << endl;
    }
public:
    
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        typedef pair<int,int> IntPair;
        typedef priority_queue<IntPair, vector<IntPair>, greater<IntPair>> PriorityQueue;
        
        // asc sorted by {weight, index}
        PriorityQueue idle;
        // asc sorted by {time, index}
        PriorityQueue busy;
    
        for(int i=0; i<servers.size(); i++){
            idle.push({servers[i], i});
        }
        
        //print(idle);
        
        int time = 0;
        vector<int> ans;
        for(int i=0; i<tasks.size(); i++) {
            time = max(i, time);

            //check the tasks finished
            while(true) { 
                while(!busy.empty()){
                    auto& t = busy.top().first;
                    auto& id = busy.top().second;
                    if (t > time) break;
                    idle.push({servers[id], id});
                    busy.pop();
                }
                if (!idle.empty())  break;
                //set the time to the fisrt finish running task 
                time = busy.top().first;
            }
            
            //process the current task
            auto& id = idle.top().second;
            ans.push_back(id);
            busy.push({time + tasks[i], id});
            idle.pop();
        }
        
        return ans;
    }
};