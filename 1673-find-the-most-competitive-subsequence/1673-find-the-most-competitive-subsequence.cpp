class Solution {
public:
    vector<int> mostCompetitive(vector<int>& N, int K) {
        int len = N.size();
        int moves = len - K;
        for (int i = 0, j = 1; j < len;) {
            while (moves && i >= 0 && N[j] < N[i])
                i--, moves--;
            N[++i] = N[j++];
        }
        return vector<int>(N.begin(), N.begin() + K);
    }
};

static int fastIO = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
