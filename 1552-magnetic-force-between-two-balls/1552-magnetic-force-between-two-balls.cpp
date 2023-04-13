class Solution {
    bool valid(vector<int> &A, int d, int m) {
        int prev = -1;
        for (int i = 0; i < A.size(); ++i) {
            if (prev != -1 && A[i] - prev < d) continue;
            if (--m == 0) return true;
            prev = A[i];
        }
        return false;
    }
public:
    int maxDistance(vector<int>& A, int m) {
        sort(begin(A), end(A));
        int L = 1, R = A.back() - A[0];
        while (L <= R) {
            int M = (L + R) / 2;
            if (valid(A, M, m)) L = M + 1;
            else R = M - 1;
        }
        return R;
    }
};