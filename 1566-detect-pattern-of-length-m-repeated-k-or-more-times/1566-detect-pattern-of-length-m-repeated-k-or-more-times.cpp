class Solution {
public:
    bool containsPattern(vector<int>& A, int m, int k) {
        int N = A.size();
        if (m * k > A.size()) return false;
        for (int i = 0; i <= N - m * k; ++i) {
            bool valid = true;
            for (int j = 1; j < k && valid; ++j) {
                for (int x = 0; x < m && valid; ++x) {
                    if (A[i + m * j + x] != A[i + x]) valid = false;
                }
            }
            if (valid) return true;
        }
        return false;
    }
};