class Solution {
public:
    void rotate(vector<vector<char>>& src, vector<vector<char>>& dest) {
        int m = src.size();
        for(int row=0; row<dest.size(); row++) {
            for(int col=0; col<dest[row].size(); col++) {
                dest[row][col] = src[m-col-1][row];
            }
        }
    }
    void gravity(vector<vector<char>>& box) {
        int m = box.size();
        int n = box[0].size();
        for(int col=0; col<n; col++) {
            int bottom = m - 1;
            for(int row=m-1; row>=0; row-- ) {
                
                if (box[row][col] == '#') {
                    box[row][col] = '.';
                    box[bottom][col] = '#';
                    bottom--;
                }else if (box[row][col] == '*') {
                    bottom = row-1;
                }
            }
        }
    }
    
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row = box.size();
        int col = box[0].size();
        vector<vector<char>> result(col, vector<char>(row,'.'));
        rotate(box, result);
        gravity(result);
        return result;
    }
};