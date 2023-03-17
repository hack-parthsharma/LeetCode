class Solution {
private:
    // Euclidean algorithm
    // https://en.wikipedia.org/wiki/Euclidean_algorithm
    int gcd(int a, int b) {
        while (a != b ) { 
            if (a > b ) a -= b;
            else b -= a;
        }
        return a;
    }
    void print(vector<int>& v, int len, vector<int>& nums){
        cout << "[";
        for(int i=0; i< len; i++) {
            cout << v[i] <<"("<< nums[v[i]]<<"), ";
        }
        cout << v[len] <<"("<<nums[v[len]]<<")]"<< endl;
    }
    
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        for(auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
       
        int n = nums.size();
        vector<int> result(n, -1);
        
        vector<int> path(n, -1);
        path[0] = 0;
        
        // primePos[num] = {position, level};
        vector<vector<pair<int, int>>> primePos(51, vector<pair<int, int>>());
        
        getCoprimesDFS(-1, 0, nums, graph, path, 0, primePos, result);
    
        return result;
    }
    
    void getCoprimesDFS(int parent, int root,
                        vector<int>& nums,
                        unordered_map<int, vector<int>>& graph,
                        vector<int>& path, int pathLen,
                        vector<vector<pair<int, int>>>& primePos,
                        vector<int>& result) {

        int max_level = -1;
        // find the previous closest prime 
        for(int n = 0; n < primePos.size(); n++) {
            auto& pos = primePos[n];
            //  no position || not co-prime
            if ( pos.size() <=0  || gcd(nums[root], n) != 1) continue; 
            if (pos.back().second > max_level && pos.back().first != root) {
                max_level = pos.back().second;
                result[root] =  pos.back().first;
            }

        }
        
        primePos[nums[root]].push_back({root, pathLen});
        for (auto& child : graph[root]) {
            if (child == parent) continue; // don't go back
            path[pathLen+1] = child; // for debug
            getCoprimesDFS(root, child, nums, graph, path, pathLen + 1, primePos, result);
        }
        primePos[nums[root]].pop_back();
    }
};