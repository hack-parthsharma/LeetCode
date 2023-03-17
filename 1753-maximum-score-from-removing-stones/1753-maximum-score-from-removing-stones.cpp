class Solution {
private:
    bool can_move(int a, int b, int c) {
        int cnt = 0 ;
        if ( a > 0 ) cnt++;
        if ( b > 0 ) cnt++;
        if ( c > 0 ) cnt++;
        return cnt >= 2;
    }

    void swap(int& x, int& y){
        int t = x;
        x = y;
        y = t;
    }

    void sort(int& a, int& b, int& c) {

        if (a < b) swap(a, b);
        if (b < c) swap(b, c);
        if (a < b) swap(a, b);

    }
public:
    int maximumScore(int a, int b, int c) {
        return maximumScore_math(a, b, c); //0
        return maximumScore_loop(a, b, c); //20ms
    }
    int maximumScore_loop(int a, int b, int c) {
        //the optimal way it always remove one stone from the biggest 2 piles
        int score = 0;
        while ( can_move(a, b ,c) ) {
            score++;
            sort(a, b ,c);
             a--; b--;
        }
        return score;

    }

    int maximumScore_math(int a, int b, int c) {
        // sort a > b > c
        sort(a, b, c);

        // if `a` is large enough which always has stone for `b` and `c`
        if ( b+c <= a ) return b+c;

        //if b+c > a, which means we always can find two stones, so the score is (a+b+c)/2
        return (a+b+c)/2;

    }
};