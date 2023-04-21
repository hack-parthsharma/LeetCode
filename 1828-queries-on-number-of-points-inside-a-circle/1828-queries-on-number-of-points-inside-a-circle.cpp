class Solution {
private:
    //refer to: https://stackoverflow.com/a/7227057/13139221
    bool inCircle( vector<int>& point,  vector<int>& circle ) {
        int x = point[0], y = point[1];
        int xo = circle[0], yo = circle[1], r = circle[2];
        
        int dx = abs(x-xo);
        if ( dx > r ) return false;
        int dy = abs(y-yo);
        if ( dy > r ) return false;
        if ( dx + dy <= r ) return true;
        return ( dx*dx + dy*dy <= r*r );
    }
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for(auto& c : queries) {
            int cnt = 0;
            for(auto& p : points) {
                if ( inCircle(p, c) ) cnt++;
            }
            result.push_back(cnt);
        }
        return result;
    }
};