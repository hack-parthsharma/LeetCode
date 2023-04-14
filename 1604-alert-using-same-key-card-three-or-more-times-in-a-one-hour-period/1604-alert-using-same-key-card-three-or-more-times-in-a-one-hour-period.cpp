class Solution {
public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string, vector<int>> m;
        for (int i = 0; i < keyName.size(); ++i) {
            auto &key = keyName[i], &time = keyTime[i];
            int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3));
            m[key].push_back(t);
        }
        vector<string> ans;
        for (auto &[key, times] : m) {
            sort(begin(times), end(times));
            for (int i = 2; i < times.size(); ++i) {
                if (times[i] - times[i - 2] > 60) continue;
                ans.push_back(key);
                break;
            }
        }
        sort(begin(ans), end(ans));
        return ans;
    }
};