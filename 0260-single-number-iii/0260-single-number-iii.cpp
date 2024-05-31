class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(int num: nums) xor_all ^= num;
        int setbit = 1;
        while((setbit & xor_all) == 0) 
            setbit <<= 1;

        vector<int> result(2);

        // We basically split the numbers into two sets.
        // All numbers in first set will have a bit in the setbit position.
        // Second set of numbers, will have 0 in the setbit position.
        for(int num: nums) {
            if(num & setbit) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};
