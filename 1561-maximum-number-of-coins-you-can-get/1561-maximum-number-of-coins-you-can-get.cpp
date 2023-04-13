class Solution {
public:
    int maxCoins(vector<int>& A) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1, ans = 0;
        while (i < j) {
            ++i;
            --j;
            ans += A[j--];
        }
        return ans;
    }
};