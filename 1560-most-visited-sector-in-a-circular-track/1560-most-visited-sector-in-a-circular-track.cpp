class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& A) {
        vector<int> cnt(n + 1);
        int from = A[0];
        cnt[from]++;
        for (int i = 1; i < A.size(); ++i) {
            int to = A[i];
            while (from != to) {
                ++from;
                if (from > n) from = 1;
                cnt[from]++;
            }
        }
        vector<int> ans;
        int mx = *max_element(begin(cnt), end(cnt));
        for (int i = 1; i <= n; ++i) {
            if (mx == cnt[i]) ans.push_back(i);
        }
        return ans;
    }
};