class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < pieces.size(); i++) {
            map[pieces[i][0]] = pieces[i];
        }
        int i = 0;
        while (i < arr.size()) {
            if (map[arr[i]].size() == 0) {
                return false;
            } else {
                vector<int> vec = map[arr[i]];
                for (int j = 0; j < vec.size(); j++) {
                    if (arr[i] == vec[j]) {
                        i++;
                    } else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
