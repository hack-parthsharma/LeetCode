class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        int maxNum = 1; //at least, we can make 0
        
        //sort the coins
        sort(coins.begin(), coins.end());
        
        //If we can make X, it means we can make [1,2,3,4,...X]
        //So, if Y <= X, then we can make [Y+1, Y+2, Y+3.... Y+X]
        //It meas we can make X+Y
        for (auto& c : coins) {
            if (c > maxNum) break;
            maxNum += c;
        }
        return maxNum;
    }
};