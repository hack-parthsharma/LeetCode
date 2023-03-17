class Solution {
public:

    bool threeConsecutiveOdds(vector<int>& arr) {
        int cnt = 0;
        for (auto n : arr) {
            if ( n % 2 ) cnt++;
            else cnt = 0;
            if (cnt >=3) return true;
        }
        return false;
    }
};