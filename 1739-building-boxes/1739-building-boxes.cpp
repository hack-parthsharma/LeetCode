class Solution {
private:
    int total(long h){
        return h * (h+1) * (h+2) / 6;
    }
public:
    int minimumBoxes(int n) {
        //find the maxiumn height which total(height) <= n
        //binary search
        int left = 1, right = pow(6l*n, 1.0/3) ;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int t = total(mid);
            if ( t == n ) return mid*(mid+1l)/2;
            if ( t < n) left = mid + 1;
            else right = mid - 1;
        }
        int height = right;
        int remind = n - total(height);
        int bottom = height * (height+1l)/2 ;
        //cout << "n=" << n << ", height=" << height << 
        //    ", bottom = " << bottom << ", remind=" << remind << endl;
        
        //find teh maxium h which sum(1..h) <= remind
        //binary search
        left = 1; right = sqrt(2*remind);
        while ( left <= right) {
            int mid = left + (right - left)/2;
            int h = mid*(mid+1)/2;
            if ( h == remind) return bottom + mid;
            if ( h < remind) left = mid + 1;
            else right = mid -1;
        }
        //cout << "left=" << left << ", right=" << right << endl;
        return bottom + left;
    }
};