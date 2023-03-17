class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int st[2] = {0};
        for(auto s: students) {
            st[s]++;
        }
        int cnt = 0;
        for(auto& san : sandwiches){
            if (st[san] == 0) break;
            st[san]--;
            cnt++;
        }
        return students.size() - cnt;
    }
};
