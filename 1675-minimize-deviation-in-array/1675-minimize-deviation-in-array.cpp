class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = nums.size();
        vector<vector<int>> seq(n);
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) {
                seq[i].emplace_back(nums[i]);
                seq[i].emplace_back(nums[i] * 2);
            }
            else {
                while (!(nums[i] & 1)) {
                    seq[i].emplace_back(nums[i]);
                    nums[i] >>= 1;
                }
                seq[i].emplace_back(nums[i]);
                reverse(seq[i].begin(), seq[i].end());
            }
        }

        vector<int> next(n, 0);
        auto cmp = [&] (const int & a, const int & b) {
            return seq[a][next[a]] > seq[b][next[b]];
        };

        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        int minVal = INT_MAX, maxVal = INT_MIN, resMax = INT_MAX, resMin = 0;
        for (int i = 0; i < n; ++i) {
            pq.emplace(i);
            maxVal = max(maxVal, seq[i][0]);
        }

        while (!pq.empty()) {
            int pos = pq.top(); pq.pop();
            minVal = seq[pos][next[pos]];

            int gap1 = maxVal - minVal, gap2 = resMax - resMin;
            if (gap1 < gap2 || (gap1 == gap2 && minVal < resMin)) {
                resMin = minVal;
                resMax = maxVal;
            }

            if (next[pos] == (int)seq[pos].size() - 1) break;

            ++next[pos];
            maxVal = max(maxVal, seq[pos][next[pos]]);
            pq.emplace(pos);
        }

        return resMax - resMin;
    }
};