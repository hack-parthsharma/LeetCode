class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& A) {
        int ans = 0;
        for (int len = 1; len <= A.size(); len += 2) {
            for (int i = 0; i <= A.size() - len; ++i) {
                for (int j = 0; j < len; ++j) ans += A[i + j];
            }
        }
        return ans;
    }
};