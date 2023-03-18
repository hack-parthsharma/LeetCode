class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int carry = K;
        for (int i = A.size() - 1; i >= 0 && carry > 0; i--) {
            int a = A[i] + carry;
            A[i] = a % 10 ;
            carry = a / 10;
        }

        while ( carry > 0 ) {
            A.insert(A.begin(), carry%10);
            carry /= 10;
        }

        return A;
    }
};