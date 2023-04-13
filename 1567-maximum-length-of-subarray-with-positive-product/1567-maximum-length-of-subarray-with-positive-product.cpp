class Solution {
public:
    int getMaxLen(vector<int>& A) {
        int N = A.size(), i = 0, ans = 0;
        while (i < N) {
            while (i < N && A[i] == 0) ++i;
            if (i == N) break;
            int start = i, cnt = 0, first = -1;
            for (; i < N && A[i] != 0; ++i) {
                cnt += A[i] < 0;
                if (A[i] < 0 && first == -1) first = i; 
                if (cnt % 2 == 0) ans = max(ans, i - start + 1);
                else ans = max(ans, i - first);
            }
        }
        return ans;
    }
};