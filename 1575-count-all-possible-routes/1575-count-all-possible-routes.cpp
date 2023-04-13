class Solution {
    long dp[101][201] = {}, mod = 1e9+7, finish;
    int dist(vector<int> &A, int a, int b) {
        return abs(A[a] - A[b]);
    }
    int dfs(vector<int> &A, int start, int fuel) {
        if (dp[start][fuel]) return dp[start][fuel];
        long ans = 0;
        if (start == finish) ans++;
        for (int i = 0; i < A.size(); ++i) {
            if (i == start || dist(A, start, i) + dist(A, i, finish) > fuel) continue;
            ans = (ans + dfs(A, i, fuel - dist(A, i, start))) % mod;
        }
        return dp[start][fuel] = ans;
    }
public:
    int countRoutes(vector<int>& A, int start, int finish, int fuel) {
        this->finish = finish;
        return dfs(A, start, fuel);
    }
};