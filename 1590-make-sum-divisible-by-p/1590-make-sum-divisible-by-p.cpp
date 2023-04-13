class Solution {
public:
    int minSubarray(vector<int>& A, int p) {
        long N = A.size(), sum = 0, total = 0, ans = N;
        for (int n : A) total = (total + n) % p;
        if (total == 0) return 0;
        unordered_map<int, int> m{ {0,-1} };
        for (int i = 0; i < N; ++i) {
            sum = (sum + A[i]) % p;
            int r = (sum - total + p) % p;
            if (m.count(r)) ans = min(ans, (long)i - m[r]);
            m[sum] = i;
        }
        return ans == N ? -1 : ans;
    }
};