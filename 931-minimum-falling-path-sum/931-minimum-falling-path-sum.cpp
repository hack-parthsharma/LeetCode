class Solution {
private:
    int min(int x, int y) {
        return x < y ? x: y;
    }
    int min( int x, int y, int z) {
        return min(min(x, y),z);
    }
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = INT_MAX;
        
        for (int i=0; i<A.size(); i++) {
            for (int j=0; j<A[i].size(); j++){
                //find the minimal item in previous row, and add it into the current item
                if (i > 0) {
                    if (j == 0 ){
                       A[i][j] += min( A[i-1][j], A[i-1][j+1]); 
                    } else if ( j + 1 == A[i].size()) {
                       A[i][j] += min( A[i-1][j], A[i-1][j-1]); 
                    }else {
                        A[i][j] += min( A[i-1][j], A[i-1][j-1], A[i-1][j+1]);
                    }
                }
                
                if ( i + 1 == A.size() ) {
                    m = min(m, A[i][j]);
                }
            }
        }
        
        return m;
    }
};