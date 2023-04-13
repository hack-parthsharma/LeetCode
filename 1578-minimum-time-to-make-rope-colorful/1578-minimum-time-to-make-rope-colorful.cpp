class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        int N = s.size(), ans = 0;
        for (int i = 0; i + 1 < N; ++i) {
            if (s[i] != s[i + 1]) continue;
            if (cost[i] > cost[i + 1]) swap(cost[i], cost[i + 1]);
            ans += cost[i];
        }
        return ans;
    }
};