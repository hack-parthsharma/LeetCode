class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        
        int m = 1 + 2 + 3 + 4 + 5 + 6 + 7;
        // we know
        //     week1 = 0*7 + m
        //     week2 = 1*7 + m 
        //     week3 = 2*7 + m 
        //     weekn = (n-1)*7 + m
        // So, 
        //     week1 + week2 + week3 + ....+ weekn 
        //   = n*m + 7*(0+1+2+..n-1)
        //   = n*m + 7*(n-1)*n/2
        
        int money = weeks*m + 7 * (weeks-1) * weeks / 2;
        
        // for the rest days
        // every day needs to add  previous `weeks * 1`, it is  days* weeks
        // then add from 1 to days
        money += (days*weeks + days*(days+1)/2);
        
        return money;
    }
};