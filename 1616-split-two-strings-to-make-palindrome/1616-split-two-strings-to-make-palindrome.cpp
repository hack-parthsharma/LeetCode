class Solution {
    bool check(string a, string b) {
        int N = a.size(), i = N / 2;
        while (i - 1 >= 0 && a[i - 1] == a[N - i]) --i; // a[i..(N-i-1)] is palindrome
        reverse(begin(b), end(b));
        return a.substr(0, i) == b.substr(0, i) || a.substr(N - i) == b.substr(N - i);
    }
public:
    bool checkPalindromeFormation(string a, string b) {
        return check(a, b) || check(b, a);
    }
};