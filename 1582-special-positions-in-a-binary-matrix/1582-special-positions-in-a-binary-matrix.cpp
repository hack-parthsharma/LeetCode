class Solution {
public:
    int numSpecial(vector<vector<int>>& A) {
        int M = A.size(), N = A[0].size(), ans = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (A[i][j] != 1) continue;
                int row = 0, col = 0;
                for (int x = 0; x < N && row <= 1; ++x) row += A[i][x];
                if (row > 1) continue;
                for (int x = 0; x < M && col <= 1; ++x) col += A[x][j];
                ans += col == 1;
            }
        }
        return ans;
    }
};