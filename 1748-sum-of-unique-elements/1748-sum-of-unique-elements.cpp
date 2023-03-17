class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        return sumOfUnique_special(nums);
        return sumOfUnique_general(nums);
    }
    
    int sumOfUnique_general(vector<int>& nums) {
        enum stat {UNIQ, DUP};
        unordered_map<int, stat> dict;
        int sum = 0;
        for (auto i : nums) {
            if (dict.find(i) == dict.end()){
                sum += i;
                dict[i] = UNIQ;
            } else {
                if (dict[i] == UNIQ) {
                    sum -= i;
                    dict[i] = DUP;
                }
            }
            
        }
        return sum;
    }
    
    int sumOfUnique_special(vector<int>& nums) {
        //because we have constraint: 1 <= nums[i] <= 100
        //we can use array instead of map 
        enum stat {NO=0,UNIQ=1,DUP=2};
        stat dict[100]={NO};
        int sum = 0;
        for (auto i : nums) {
            switch(dict[i-1]) {
                case NO:
                    sum += i;
                    dict[i-1] = UNIQ;
                    break;
                case UNIQ:
                    sum -= i;
                    dict[i-1] = DUP;
                    break;
                default:
                    continue;
            }
        }
        return sum;
    }
    
};