class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int m = arr[0] = 1;
        for(int i=0; i<arr.size()-1; i++) {
            if (abs(arr[i] - arr[i+1]) <= 1) {
                m = max(arr[i], arr[i+1]);
                continue;
            }
            arr[i+1] = arr[i] + 1;
            m = arr[i+1];
        }
        return m;
    }
};