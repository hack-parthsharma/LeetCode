class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int result = -1;
        int distance = INT_MAX;
        for(int i=0; i<points.size(); i++) {
            if ( x  != points[i][0]  && y != points[i][1] ) continue;
            int dist = abs(x - points[i][0]) + abs( y - points[i][1]);
            if ( distance > dist ){
                distance = dist;
                result = i;
            }
        }
        return result;
    }
};