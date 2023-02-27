class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i=0;
        while(++i) {
            int& himem = memory1 >= memory2 ? memory1 : memory2;
            if (himem < i) break;
            himem -= i;
        }
        vector<int> result={i, memory1, memory2};
        return result;
    }
};
