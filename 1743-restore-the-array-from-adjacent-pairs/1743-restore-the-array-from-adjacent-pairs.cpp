class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        // only two numbers have one neighbour
        // start from one of them to travel all number.
        
        unordered_map<int, vector<int>> dict;
        for(auto& pair : adjacentPairs) {
            dict[pair[0]].push_back(pair[1]);
            dict[pair[1]].push_back(pair[0]);
        }
        
        int end[2]; int i=0;
        for (auto& [key, pair] : dict) {
            if(pair.size()==1) end[i++] = key;
            if (i>1) break;
        }
        //cout << "start=" << end[0] <<", end=" << end[1] << endl;
        vector<int> result(1, end[0]);
        int start = end[0];
        int prev = -1;
        while ( start != end[1] ) {
            auto& v = dict[start];
            for(int i= 0; i< v.size(); i++) {
                if (v[i] == prev) continue;
                result.push_back(v[i]);
                prev = start;
                start = v[i];
                break;
            }
        }
        return result;
    }
};