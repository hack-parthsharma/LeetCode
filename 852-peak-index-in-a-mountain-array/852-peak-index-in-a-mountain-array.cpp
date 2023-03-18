class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        
        // Put two dummy items at head and tail to avoid Out-of-Bound Error.
        #define INT_MAX 2147483647
        #define INT_MIN (-INT_MAX - 1)
        A.insert ( A.begin() , INT_MIN );
        A.push_back(INT_MIN);
        
        //binary search
        int len = A.size();
        int left = 1, right = len - 2;
        while(left <= right) {
            int mid = left + (right - left)/2; //avoid integer overflow
            if ( A[mid-1] < A[mid] && A[mid] > A[mid+1]) return mid-1;
            if ( A[mid-1] < A[mid] && A[mid] < A[mid+1]) left = mid + 1;
            if ( A[mid-1] > A[mid] && A[mid] > A[mid+1]) right = mid - 1;
            
        }
        return -1;
    }
};
