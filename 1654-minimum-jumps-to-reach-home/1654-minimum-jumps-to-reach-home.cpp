class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int,int> visited;
        queue<pair<int,int>> positionQueue; 
        for(auto i:forbidden){
            visited[i]=true;
        }
        positionQueue.push({0,0}) ; 
        int stepCount = 0;
        while(!positionQueue.empty()){
            int size = positionQueue.size() ;
            while(size--){
                auto curr = positionQueue.front() ;
                positionQueue.pop() ;
                int num = curr.first;
                if(num == x){
                    return stepCount;
                }
               
                if(visited[num] == true){
                    continue;
                } 
                visited[num]=true;
                if(curr.second == 0 && num-b>=0) {
                    positionQueue.push({(num-b),1});
                }
                if(num <= 2000+b){
                    positionQueue.push({(num+a),0});                 
                }
            }
            stepCount++;
        }
        return -1;
    }
};