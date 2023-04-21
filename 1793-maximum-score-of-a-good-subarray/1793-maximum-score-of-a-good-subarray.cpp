class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int score = nums[k];
        int m = score;
        int left = k, right = k;
        int l = left, r = right;
        while (left>0 || right < nums.size()-1){
            
            if ( left > 0 && right < nums.size()-1 ) {
                if (nums[left-1] > nums[right+1]) {
                    left--;
                } else if (nums[left-1] < nums[right+1]) {
                    right++;
                } else {
                    left--;right++;
                }
            }else if ( left <= 0 ) {
                right++;
            }else if ( right >= nums.size() -1 ) { 
                left--;
            }else {
                break;
            }
            
            m = min(m, min( nums[left], nums[right]));
            int s = m * (right - left + 1);
            if ( s > score) {
                score = s;
                l = left;  r = right;
            }
        }
        
        //cout << "[" << l << "," << r << "] = " << score << endl;
        
        return score;
    }
};