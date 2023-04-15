class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    void connect(int a, int b) {
        int x = find(a), y = find(b);
        if (x == y) return;
        id[x] = y;
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
};
class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size();
        map<int, vector<vector<int>>> m;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) m[A[i][j]].push_back({ i, j });
        }
        vector<int> rank(M + N, 0); // rank[0..(M-1)] stores the highest ranks of the rows, rank[M..(M+N-1)] stores the highest ranks of the columns.
        vector<vector<int>> ans(M, vector<int>(N));
        for (auto &[val, pos] : m) {
            UnionFind uf(M + N);
            for (auto &p : pos) {
                int x = uf.find(p[0]), y = uf.find(p[1] + M);
                uf.connect(x, y); // for each number, connect its (representative) row and column
                rank[uf.find(x)] = max(rank[x], rank[y]);
            }
            auto next = rank;
            for (auto &p : pos) {
                int x = p[0], y = p[1], r = uf.find(x);
                ans[x][y] = next[x] = next[y + M] = rank[r] + 1;
            }
            rank = move(next);
        }
        return ans;
    }
};