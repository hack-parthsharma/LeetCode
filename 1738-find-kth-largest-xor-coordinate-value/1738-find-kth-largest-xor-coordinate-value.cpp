class Solution {
private:
    void print(vector<vector<int>>& m) {
        int row = m.size();
        int col = m[0].size();
        for (int i=0; i<row; i++) {
            for(int j=0; j<col-1; j++) {
                cout << setw(3) << m[i][j] << ",";
            }
            cout << setw(3) << m[i][col-1] << endl;
        }
        cout << endl;
    }
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> xmatrix(row, vector<int>(col, 0));
        priority_queue<int> minHeap;
        
        xmatrix[0][0] = matrix[0][0];
        minHeap.push(xmatrix[0][0]);
 
        for (int i=1; i<row; i++) {
            xmatrix[i][0] = xmatrix[i-1][0] ^ matrix[i][0];
            minHeap.push(xmatrix[i][0]);
        }
        for (int i=1; i<col; i++) {
            xmatrix[0][i] = xmatrix[0][i-1] ^ matrix[0][i];
            minHeap.push(xmatrix[0][i]);
        }
        
        for (int i=1; i<row; i++) {
            for(int j=1; j<col; j++) {
                xmatrix[i][j] = matrix[i][j] ^ 
                    xmatrix[i-1][j] ^ xmatrix[i][j-1] ^ xmatrix[i-1][j-1];
                minHeap.push(xmatrix[i][j]);
            }
        }
        //print(matrix);
        //print(xmatrix);
        while( k-- > 1) {
            minHeap.pop();
        }
        
        return minHeap.top();
    }
};