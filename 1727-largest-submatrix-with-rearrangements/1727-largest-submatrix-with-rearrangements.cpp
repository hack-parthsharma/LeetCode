class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> height (cols, 0);
        
        int result = 0;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if (matrix[r][c] == 1) height[c]++;
                else height[c] = 0;
            }
            
            vector<int> h = height;
            sort(h.begin(), h.end());
            for(int i = 0; i < cols; i++) {
                result = max(result, h[i] * ( cols - i)); 
            }
        }
        return result;
    }
};