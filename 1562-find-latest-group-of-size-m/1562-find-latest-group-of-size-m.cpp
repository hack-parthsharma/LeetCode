class Solution {
public:
    int findLatestStep(vector<int>& A, int m) {
        int N = A.size(), ans = -1;
        if (N == m) return N;
        vector<int> len(N + 2);
        for (int i = 0; i < N; ++i) {
            int n = A[i], left = len[n - 1], right = len[n + 1];
            len[n - left] = len[n + right] = left + right + 1;
            if (left == m || right == m) ans = i;
        }
        return ans;
    }
};