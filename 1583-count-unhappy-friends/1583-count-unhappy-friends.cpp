class Solution {
    unordered_map<int, unordered_map<int, int>> m;
    unordered_set<int> s;
    void unhappy(int x, int y, int u, int v) {
        if (m[x][y] < m[x][u] || m[u][v] < m[u][x]) return;
        s.insert(x);
        s.insert(u);
    }
public:
    int unhappyFriends(int n, vector<vector<int>>& pref, vector<vector<int>>& pairs) {
        for (int i = 0; i < pref.size(); ++i) {
            for (int j = 0; j < pref[i].size(); ++j) m[i][pref[i][j]] = j;
        }
        for (int i = 0; i < pairs.size(); ++i) {
            int x = pairs[i][0], y = pairs[i][1];
            for (int j = i + 1; j < pairs.size(); ++j) {
                int u = pairs[j][0], v = pairs[j][1];
                unhappy(x, y, u, v);
                unhappy(x, y, v, u);
                unhappy(y, x, u, v);
                unhappy(y, x, v, u);
            }
        }
        return s.size();
    }
};