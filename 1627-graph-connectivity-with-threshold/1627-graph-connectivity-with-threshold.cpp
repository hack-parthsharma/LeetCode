class UnionFind {
    vector<int> id;
public:
    UnionFind(int n) : id(n) {
        iota(begin(id), end(id), 0);
    }
    int find(int x) {
        return id[x] == x ? x : (id[x] = find(id[x]));
    }
    void connect(int a, int b) {
        int p = find(a), q = find(b);
        if (p == q) return;
        id[p] = q;
    }
    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};
class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& Q) {
        unordered_map<int, int> m;
        UnionFind uf(n);
        for (int i = 1 + threshold; i <= n; ++i) {
            for (int j = 2 * i; j <= n; j += i) {
                uf.connect(i - 1, j - 1);
            }
        }
        vector<bool> ans;
        for (auto &q : Q) ans.push_back(uf.connected(q[0] - 1, q[1] - 1));
        return ans;
    }
};