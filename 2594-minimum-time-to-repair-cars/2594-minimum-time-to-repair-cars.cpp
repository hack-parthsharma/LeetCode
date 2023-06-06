class Solution {
    public:
    long long repairCars(vector<int>& ranks, int cars) {
        int n = ranks.size();
        sort(ranks.begin(), ranks.end());
        long long l = 0, r = 1e18;
        while (l < r) {
            long long mid = l + (r - l) / 2;
            long long cnt = 0;
            for (int i = 0; i < n; i++) {
                cnt += (long long) (sqrt(mid / ranks[i]));
            }
            if (cnt >= cars) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};