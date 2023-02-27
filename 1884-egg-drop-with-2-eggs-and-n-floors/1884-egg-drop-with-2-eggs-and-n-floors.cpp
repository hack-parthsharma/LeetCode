class Solution {
public:
    int twoEggDrop(int n) {
        int c = 1, i=1;
        while(c < n) {
            c += i;
            i++;
        }
        return c==n ? i : i-1;
    }
};