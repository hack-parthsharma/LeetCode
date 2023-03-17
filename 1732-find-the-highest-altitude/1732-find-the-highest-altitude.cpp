class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int sum = 0;
        for (auto& n : gain) {
            sum += n;
            result = max(result, sum);
        }
        return result;
    }
};