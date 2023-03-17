class Solution {
private:
    int sum(int n) {
        int s = 0;
        for(; n > 0; n /= 10){
            s += n % 10;
        }
        return s;
    }
public:
    int countBalls(int lowLimit, int highLimit) {
        int cnt[46] ={0}; //10^5 means 9+9+9+9+9 = 45
        int m = 0;
        for (int n = lowLimit; n<=highLimit; n++) {
            int box = sum(n);
            cnt[box]++;
            m = max(m, cnt[box]);
        }
        return m;
    }
};