class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool map[256] = {false};
        for (auto c : J) {
            map[c]=true;
        }
        int cnt=0;
        for (auto c : S) {
            if (map[c])  cnt++;
        }
        return cnt;
    }
};