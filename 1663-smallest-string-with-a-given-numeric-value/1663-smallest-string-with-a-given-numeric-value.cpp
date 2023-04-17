class Solution {
public:
    string getSmallestString(int n, int k) {
        string s;
        int a = 0, z = 0;
        while (n - 1 > 0 && k - 1 < (n - 1) * 26) ++a, --k, --n;
        while (n - 1 > 0 && k - 26 >= n - 1) ++z, k -= 26, --n;
        while (a-- > 0) s += 'a';
        if (k) s += 'a' + k - 1;
        while (z-- > 0) s += 'z';
        return s;
    }
};