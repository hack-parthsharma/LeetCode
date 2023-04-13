class Solution {
public:
    bool isTransformable(string s, string t) {
        queue<int> q[10];
        for (int i = 0; i < s.size(); ++i) q[s[i] - '0'].push(i);
        for (int i = 0; i < t.size(); ++i) {
            int d = t[i] - '0';
            if (q[d].empty()) return false;
            for (int j = 0; j < d; ++j) {
                if (q[j].size() && q[j].front() < q[d].front()) return false;
            }
            q[d].pop();
        }
        return true;
    }
};