class Solution {
public:
    void put(int R, int C, int r, int c, vector<vector<int>>& res) {
        if (r>=0 && r < R && c>=0 && c<C ) {
            res.push_back({r,c});
        }
    }
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        int n =  R+C-2;
        vector<vector<int>> result;
        result.push_back({r0,c0});
        for(int i=1; i<= n; i++) {
            // from (r0-i, c0) to (r0, c0+i)
            for(int r=r0-i,c=c0;r!=r0; r++, c++)  put (R, C, r ,c, result);

            // from  (r0, c0+i) to (r0+i, c0)
            for(int r=r0, c=c0+i; c!=c0; r++, c-- ) put (R, C, r, c, result);

            // from (r0+i, c0) to (r0, c0-i)
            for (int r=r0+i, c=c0; r!=r0; r--, c--) put (R, C, r, c, result);

            // from (r0, c0-i) to (r0-i, c0)
            for (int r=r0, c=c0-i; c!=c0; r--, c++) put (R, C, r, c, result);
        }

        return result;
    }
};