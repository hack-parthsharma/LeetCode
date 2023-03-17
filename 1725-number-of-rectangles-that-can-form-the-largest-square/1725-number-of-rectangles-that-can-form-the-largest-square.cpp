class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        return countGoodRectangles2(rectangles);
        return countGoodRectangles1(rectangles); 
    }
    
    int countGoodRectangles1(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        for(auto& rect : rectangles) {
            int  len = min(rect[0], rect[1]);
            maxLen = max(maxLen, len);
        }
        
        int cnt = 0;
        for(auto& rect : rectangles) {
            if (maxLen <= rect[0] && maxLen <= rect[1]) cnt++;
        }
        return cnt;
    }
    
    int countGoodRectangles2(vector<vector<int>>& rectangles) {
        int maxLen = 0;
        int cnt = 0;
        for(auto& rect : rectangles) {
            int  len = min(rect[0], rect[1]);
            if (len > maxLen ) {
                cnt = 1;
                maxLen = len;
            }else if (len == maxLen ) {
                cnt++;
            }
        }

        return cnt;
    }
};