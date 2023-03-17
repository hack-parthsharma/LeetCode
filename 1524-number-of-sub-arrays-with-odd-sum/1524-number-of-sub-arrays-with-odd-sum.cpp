class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        //Walk through the array, and calculate the current sum
        //if current sum is odd, then all of the sum are evil previously are valid sub-array
        //if current sum is evil, then all of the sum are odd previously are valid sub-array
        int odd_sum_cnt=0, evil_sum_cnt=0;
        int sum = 0;
        long long result=0;
        for (auto a : arr) {
            sum += a;
            if (sum % 2 == 0) {
                evil_sum_cnt++;
                result += odd_sum_cnt;
            }else {
                odd_sum_cnt++;
                result += evil_sum_cnt + 1;
            }
        }

        return result % 1000000007;

    }
};