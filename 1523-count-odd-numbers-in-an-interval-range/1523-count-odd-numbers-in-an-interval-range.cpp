class Solution {
public:
    int countOdds1(int low, int high) {
        //remove the edge cases, make it as same pattern - both low and high are odd number.
        if  (high % 2 == 0) high--;
        if  (low % 2 == 0 ) low++;
        return (high-low)/2+1;
    }
    int countOdds2(int low, int high) {
        return (high+1)/2 - low/2;
    }
    int countOdds(int low, int high) {
        return countOdds2(low, high);
        return countOdds1(low, high);
    }
};