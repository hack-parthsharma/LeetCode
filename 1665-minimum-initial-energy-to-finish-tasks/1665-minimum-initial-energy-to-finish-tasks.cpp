class Solution {
public:
    int minimumEffort(vector<vector<int>>& A) {
        int N = A.size(), ans = 0, cur = 0;
        sort(begin(A), end(A), [&](auto &a, auto &b) { return (a[1] - a[0]) > (b[1] - b[0]); });
        for (int i = 0; i < N; ++i) {
            if (cur < A[i][1]) {
                ans += A[i][1] - cur;
                cur = A[i][1];
            }
            cur -= A[i][0];
        }
        return ans;
    }
};
