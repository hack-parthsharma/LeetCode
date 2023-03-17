class Cell{
public:
    int x;
    int y;
    int height;
};

class Solution {
private:
    void setHeight(vector<vector<int>>& height, 
                   queue<Cell>& q,
                   int x, int y, int h, 
                   int m, int n) 
    {
        if (x < 0 || y < 0 || x>=m || y>=n ) return;
        if (height[x][y] == -1) {
            height[x][y] = h;
            q.push({x, y, h});
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size();
        int n = isWater[0].size();
        
        vector<vector<int>> height(m, vector(n, -1));
        queue<Cell> q;
        
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j]) {
                    height[i][j] = 0;
                    q.push({i, j, 0});
                }
            }
        }
        
        while(!q.empty()){
            auto cell = q.front(); q.pop();
            setHeight(height, q, cell.x-1, cell.y, cell.height+1,  m, n);
            setHeight(height, q, cell.x+1, cell.y, cell.height+1,  m, n);
            setHeight(height, q, cell.x, cell.y-1, cell.height+1,  m, n);
            setHeight(height, q, cell.x, cell.y+1, cell.height+1,  m, n);
        }
        
        return height;
    }
                        
};