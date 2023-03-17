class Solution {
public:
    int minOperations(int n) {
        // the sum of odd number is : n*n
        // the sum of even number is: n*n+n
        /* int sum = n*n; */

        //calculate the average
        /* int average = sum / n;  //actually it is n  */

        //calculate the different between n and all of the odd number which less than `average`
        //  (n - 1) + (n - 3) + (n - 5) + (n - 7) ...
        // = m*n - (1+3+5+7+...m)   where m = n/2
        // = m*n - m*m
        // = (n/2)*n - (n/2)*(n/2)
        // = n*n/2 - n*n/4
        // = n*n/4

        return n*n/4;
    }
};