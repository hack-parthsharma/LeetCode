class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        int x = arr1[0];
        for(int i = 1; i < arr1.size(); i++) {
            x ^= arr1[i];
        }
        int y = arr2[0];
        for(int i = 1; i< arr2.size(); i++) {
            y ^= arr2[i];
        }
        return x&y;
    }
};