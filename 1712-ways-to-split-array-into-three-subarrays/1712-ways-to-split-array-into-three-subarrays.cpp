const int MOD = (int) (1e9 + 7);

class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int len = nums.size();
        vector<int> presum(len, 0);
        presum[0] = nums[0];
        for(int i=1; i<nums.size(); i++){
            presum[i] = presum[i-1] + nums[i];
        }
        
        return waysToSplit_BS(presum);  // Binary Search
        //return waysToSplit_TLE(presum); // Time Limit Error
    }
    
    int binary_search(vector<int>& presum, int left, int i, bool searchLeft ) {
        int len = presum.size();
        int l = i, r = len-1;
        int res = -1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            // if search Left, let middle item belong to left
            // if search Right, let middle item belong to right
            int x = searchLeft? 0 : 1; 
            int right = presum[len-1] - presum[m-x];
            int mid = presum[m-x] - presum[i-1];
            
            if (left <= mid && mid <= right) {
                res = m;
                if (searchLeft) r = m - 1;
                else l = m + 1;
            }else if (left > mid) {
                l = m + 1;
            }else {
                r = m -1;
            }

        }
        return res;
    }
    int waysToSplit_BS(vector<int>& presum) {
        int len = presum.size();
        long cnt = 0;
        for(int i=0; i<len-2; i++){
            if (presum[i] > (presum[len-1] - presum[i]) / 2) break;
            //find the most right position
            long l = binary_search(presum, presum[i], i+1, true);
            //find the most right position
            long r = binary_search(presum, presum[i], i+1, false);
            if (l == -1 || r == -1 ) continue;
            cnt += (r-l);
            //cout << i << " - [" << l << "," << r << "]" << endl;
        } 
        //cout << endl;
        return cnt % MOD;
    }
    
    int waysToSplit_TLE(vector<int>& presum) {
        int len = presum.size();
        int cnt = 0;
        int left, mid, right;
        for(int i=0; i<len-2; i++){
            left = presum[i];
            for (int j=i+1; j<len-1; j++) {
                mid = presum[j] - presum[i];
                right = presum[len-1] - presum[j];
                if (left <= mid && mid <= right) {
                    cnt++;
                }
            }
        } 
        
return cnt;
    }
};