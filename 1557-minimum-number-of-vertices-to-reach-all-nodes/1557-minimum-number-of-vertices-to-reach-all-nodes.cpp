class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& E) {
        vector<int> degree(n), ans;
        for (auto &e : E) degree[e[1]]++;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};