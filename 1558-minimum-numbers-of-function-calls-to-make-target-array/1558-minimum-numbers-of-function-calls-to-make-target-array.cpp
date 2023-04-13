class Solution {
public:
    int minOperations(vector<int>& A) {
        int add = 0, mul = 0;
        for (int n : A) {
            int m = 0;
            while (n) {
                if (n % 2) ++add, --n;
                else ++m, n /= 2;
            }
            mul = max(mul, m);
        }
        return add + mul;
    }
};