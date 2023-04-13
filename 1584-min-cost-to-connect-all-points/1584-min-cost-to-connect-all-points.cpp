class UnionFind {
    vector<int> id;
    int size;
public:
    UnionFind(int N) : id(N), size(N) {
        iota(begin(id), end(id), 0);
    }
    int find(int a) {
        return id[a] == a ? a : (id[a] = find(id[a]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
        --size;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
    int getSize() { return size; }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& A) {
        int N = A.size(), ans = 0;
        vector<array<int, 3>> E;
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) E.push_back({ abs(A[i][0] - A[j][0]) + abs(A[i][1] - A[j][1]), i, j });
        }
        make_heap(begin(E), end(E), greater<array<int, 3>>());
        UnionFind uf(N);
        while (uf.getSize() > 1) {
            pop_heap(begin(E), end(E), greater<array<int, 3>>());
            auto [w, u, v] = E.back();
            E.pop_back();
            if (uf.connected(u, v)) continue;
            uf.connect(u, v);
            ans += w;
        } 
        return ans;
    }
};