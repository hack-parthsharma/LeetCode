class Solution {
public:
    bool isEven(int& x) {
        return x % 2 == 0;
    }
    vector<int> sortArrayByParity(vector<int>& A) {
        //two pointer, one from left to right, another from right to left
        // if left is odd number and right is even number, switch them
        int l=0, r=A.size()-1;
        while ( l < r ) {
            if ( !isEven(A[l]) && isEven(A[r]) ) swap(A[l], A[r]);
            if ( isEven(A[l]) ) l++;
            if ( !isEven(A[r]) ) r--;
        }
        return A;
    }
};