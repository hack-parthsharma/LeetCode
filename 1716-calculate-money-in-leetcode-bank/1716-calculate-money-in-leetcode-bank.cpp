class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        
        int m = 1 + 2 + 3 + 4 + 5 + 6 + 7;
        
        int money = weeks*m + 7 * (weeks-1) * weeks / 2;
        
        money += (days*weeks + days*(days+1)/2);
        
        return money;
    }
};