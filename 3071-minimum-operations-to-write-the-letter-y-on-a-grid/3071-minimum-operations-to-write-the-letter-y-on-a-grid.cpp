class Solution {
 public:
  int minimumOperationsToWriteY(vector<vector<int>>& grid) {
    return min({getOperations(grid, 0, 1), getOperations(grid, 0, 2),
                getOperations(grid, 1, 0), getOperations(grid, 1, 2),
                getOperations(grid, 2, 0), getOperations(grid, 2, 1)});
  }

 private:
  int getOperations(const vector<vector<int>>& grid, int a, int b) {
    const int n = grid.size();
    const int mid = n / 2;
    int operations = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if ((i < mid && (i == j || i + j == n - 1)) || (i >= mid && j == mid)) {
          if (grid[i][j] != a)
            ++operations;
        } else if (grid[i][j] != b) {
          ++operations;
        }
    return operations;
  };
};