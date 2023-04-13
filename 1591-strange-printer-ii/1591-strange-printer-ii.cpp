class Solution {
    bool removable(vector<vector<int>> &G, vector<vector<int>> &pos, int c) {
        for (int i = pos[c][0]; i <= pos[c][2]; ++i) {
            for (int j = pos[c][1]; j <= pos[c][3]; ++j) {
                if (G[i][j] != c && G[i][j] != 0) return false;
            }
        }
        for (int i = pos[c][0]; i <= pos[c][2]; ++i) {
            for (int j = pos[c][1]; j <= pos[c][3]; ++j) G[i][j] = 0;
        }
        return true;
    }
public:
    bool isPrintable(vector<vector<int>>& G) {
        int M = G.size(), N = G[0].size();
        vector<vector<int>> pos(61, {M, N, 0, 0});
        unordered_set<int> colors, remove;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                int c = G[i][j];
                colors.insert(c);
                pos[c][0] = min(pos[c][0], i);
                pos[c][1] = min(pos[c][1], j);
                pos[c][2] = max(pos[c][2], i);
                pos[c][3] = max(pos[c][3], j);
            }
        }
        while (colors.size()) {
            for (int c : colors) {
                if (removable(G, pos, c)) remove.insert(c);
            }
            if (remove.empty()) return false;
            for (int c : remove) colors.erase(c);
            remove.clear();
        }
        return true;
    }
};