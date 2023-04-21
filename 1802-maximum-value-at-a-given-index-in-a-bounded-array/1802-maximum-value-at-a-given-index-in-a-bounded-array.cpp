class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        // at least, put the bottom layer
        int maxValue = 1;
        maxSum -= n;
        int layer = 1;
        
        int points;
        while ( maxSum > 0 ) {
            // how many 1 we need
            points = (2 * layer - 1);
            
            // how many 1 exceed the right bound
            int right = (index + layer-1) - (n-1);
            if (right > 0)  points -= right;
            // how many 1 exceed the left bound
            int left = (layer - index - 1);
            if (left > 0)  points -= left;
           
            //  points >= n  -  we just need `n` for the rest layers 
            //  maxSum < points -  if we  haven't enough points 
            if (points >= n || maxSum < points) break;
            
            
            maxSum -= points;
            layer++;
            maxValue++;
        }
        // maxSum/n - we just need `n` for the rest layers
        return maxValue += (maxSum/n);
    }
};