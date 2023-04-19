class Solution {
public:
    int minimumIncompatibility(vector<int>& A, int k) {
        int N = A.size(), M = 1 << N, sz = N / k;
        if (k == 1) {
            set<int> s(begin(A), end(A));
            return s.size() == A.size() ? *s.rbegin() - *s.begin() : -1;
        }
        if (k == N) return 0;
        sort(begin(A), end(A));
        int dp[M][N];
        memset(dp, 0x3f, sizeof(dp)); // infinity
        memset(dp[0], 0, sizeof(dp[0]));
        for (int mask = 1; mask < M; ++mask) {
            if (__builtin_popcount(mask) % sz) {
                for (int pre = 0; pre < N; ++pre) {
                    for (int p = pre + 1; p < N; ++p) {
                        if ((mask & (1 << p)) && A[p] > A[pre]) {
                            dp[mask][pre] = min(dp[mask][pre], dp[mask - (1 << p)][p] + A[p] - A[pre]);
                        }
                    }
                }
            } else {
                for (int p = 0; p < N; ++p) {
                    if (mask & (1 << p)) dp[mask][0] = min(dp[mask][0], dp[mask - (1 << p)][p]);
                }
                for (int i = 1; i < N; ++i) dp[mask][i] = dp[mask][0];
            }
        }
        return dp[M - 1][0] > 10000 ? -1 : dp[M - 1][0];
    }
};