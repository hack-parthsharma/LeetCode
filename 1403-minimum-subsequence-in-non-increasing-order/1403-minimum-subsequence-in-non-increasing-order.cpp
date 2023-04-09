class Solution {
public:
    vector<int> minSubsequence(vector<int>& A) {
        sort(A.begin(), A.end(), greater<int>());
        int sum = accumulate(begin(A), end(A), 0);
        int s = 0;
        vector<int> ans;
        for (int i = 0; i < A.size(); ++i) {
            s += A[i];
            ans.push_back(A[i]);
            if (s > sum - s) break;
        }
        return ans;
    }
};
