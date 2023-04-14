class Solution {
    int seen[16] = {}, incl[16] = {}; // incl[i] == 1 if node `i` is included in mask
    vector<int> g[16];
    void dfs(int u, int &cnt) {
        if (!incl[u] || seen[u]) return;
        ++cnt;
        seen[u] = 1;
        for (int v : g[u]) dfs(v, cnt);
    }
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& E) {
        int dist[16][16] = {};
        memset(dist, 0x3f, sizeof(dist));
        for (auto &e : E) {
            int u = e[0] - 1, v = e[1] - 1;
            g[u].push_back(v);
            g[v].push_back(u);
            dist[u][v] = dist[v][u] = 1;
        }
        for (int k = 0; k < n; ++k) { // use floyd to get the minimal distance between every two nodes.
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        vector<int> ans(n - 1);
        for (int mask = 1; mask < (1 << n); ++mask) {
            memset(seen, 0, sizeof(seen));
            memset(incl, 0, sizeof(incl));
            int cnt = __builtin_popcount(mask), start;
            if (cnt < 2) continue;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    incl[i] = 1;
                    start = i;
                }
            }
            int c = 0;
            dfs(start, c); // count how many nodes we can visit.
            if (cnt != c) continue; // not all nodes are connected
            int mx = 0;
            for (int i = 0; i < n; ++i) {
                if (!incl[i]) continue;
                for (int j = i + 1; j < n; ++j) {
                    if (!incl[j]) continue;
                    mx = max(mx, dist[i][j]);
                }
            }
            ++ans[mx - 1];
        }
        return ans;
    }
};