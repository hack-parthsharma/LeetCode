class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int n = light.size();
        vector<bool> on(n, false);
        int left = 0; //tracking the most left place that all bubls are truned on.
        int result = 0;
        for(int i=0; i<light.size(); i++){
            on[light[i]-1] = true;
            while (left < n && on[left]) left++;
            //if the bulbs are on left is equal to current bulbs we trun on.
            //then they all are blue.
            if (left == i+1) result++; 
        }
        return result;
    }
};