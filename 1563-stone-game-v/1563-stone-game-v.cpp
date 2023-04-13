class Solution {
    int dp[501][501] = {}, N;
    vector<int> sum;
    int dfs(vector<int> &A, int i, int j){
        if (i == j) return 0;
        if (dp[i][j]) return dp[i][j];
        int val = 0;
        for (int k = i; k < j; ++k) {
            int left = sum[k + 1] - sum[i], right = sum[j + 1] - sum[k + 1];
            if (left < right) val = max(val, dfs(A, i, k) + left);
            else if (right < left) val = max(val, dfs(A, k + 1, j) + right);
            else val = max({ val, dfs(A, i, k) + left, dfs(A, k + 1, j) + right });
        }
        return dp[i][j] = val;
    }
public:
    int stoneGameV(vector<int>& A) {
        N = A.size();
        sum.assign(N + 1, 0);
        for (int i = 0; i < N; ++i) sum[i + 1] = sum[i] + A[i];
        return dfs(A, 0, N - 1);
    }
};