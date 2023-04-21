class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> result(k, 0);
        unordered_map<int, set<int>> uam;
        for (auto& log : logs) {
            uam[log[0]].insert(log[1]);
        }
        for (auto& [id, t] : uam) {
            if (t.size() <= k) {
                result[t.size()-1]++;
            }
        }
        return result;
    }
};