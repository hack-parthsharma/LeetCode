class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return change_dp(amount, coins);
        return change_recursive(amount, coins); // Time Limit Error
    }
    
    
    int change_recursive(int amount, vector<int>& coins) {
        int result = 0;
        change_recursive_helper(amount, coins, 0, result);
        return result;
    }
    
    // the `idx` is used for remove the duplicated solutions.
    void change_recursive_helper(int amount, vector<int>& coins, int idx, int& result) {
        if (amount == 0) { 
            result++; 
            return;
        }
    
        for ( int i = idx; i < coins.size(); i++ ) {
            if (amount < coins[i]) continue;
            change_recursive_helper(amount - coins[i], coins, i, result);
        }
        return;
    }
    
    int change_dp(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (int i=0; i<coins.size(); i++) {
            for(int n=1; n<=amount; n++) {
                if (n >= coins[i]) {
                    dp[n] += dp[n-coins[i]];
                }
            }
        }

        return dp[amount];
    }
};
