class Solution {
public:
    int specialArray(vector<int>& A) {
        sort(begin(A), end(A));
        int N = A.size();
        for (int i = 0; i <= N; ++i) {
            int cnt = N - (lower_bound(begin(A), end(A), i) - begin(A));
            if (cnt == i) return i;
        }
        return -1;
    }
};