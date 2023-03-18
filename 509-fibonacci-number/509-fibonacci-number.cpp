class Solution {
public:
    int fib(int N) {
        if (N < 2 )  return N;
        int first = 0, second = 1;

        for ( N-=1; N > 0; N-- ) {
            second += first;
            first = second - first;
        }
        return second;
    }
};