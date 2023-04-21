class Solution {
private:
    int rev(int n) {
        int x = 0;
        while(n > 0) {
            x = x*10 + (n % 10);
            n /= 10;
        }
        return x;
    }

public:
    int countNicePairs(vector<int>& nums) {
        return countNicePairs02(nums);
        return countNicePairs01(nums);
    }
    int countNicePairs01(vector<int>& nums) {
        // suppose n' = rev(n) 
        // define:  a + b' == b + a'
        //   then:  a - a' == b - b'
        
        unordered_map<int, int> stat;
        for(auto& n : nums) {
            stat[n-rev(n)]++;
            
        }
        
        //if there are n elements  has same value, 
        // then there are  n*(n-1)/2 unique pairs.
        int result = 0;
        for(auto& [n, cnt] : stat) {
            result  =  (result + cnt * (cnt -1l) / 2)  % 1000000007;
        }
        return result;
    }
    
    int countNicePairs02(vector<int>& nums) {
        // suppose n' = rev(n) 
        // define:  a + b' == b + a'
        //   then:  a - a' == b - b'
        int result = 0;
        unordered_map<int, int> stat;
        for(auto& n : nums) {
            int delta = n-rev(n);
            stat[delta]++;
            result = (result + (stat[delta] - 1l)) % 1000000007 ;
        }
        
  
return result ;
    }
};
