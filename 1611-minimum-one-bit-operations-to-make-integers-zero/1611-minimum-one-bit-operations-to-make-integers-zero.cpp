class Solution {
    inline unsigned lowbit(unsigned x) { return x & -x; }
public:
    int minimumOneBitOperations(int n) {
        if (n <= 1) return n;
        unsigned first = ~0;
        while (first & n) first <<= 1;
        first = lowbit(first >> 1);
        unsigned second = (first >> 1) & n, rest = minimumOneBitOperations(n & ~first & ~second);
        return second ? first + rest : (first << 1) - 1 - rest;
    }
};