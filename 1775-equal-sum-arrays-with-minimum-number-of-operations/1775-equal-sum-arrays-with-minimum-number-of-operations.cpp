class Solution { 
private:
    void print(vector<int>& n) {
        cout <<"[";
        for(int i=0; i< n.size() - 1; i++) {
            cout << n[i] << ",";
        }
        cout << n[n.size()-1] << "]" <<endl;
    }
private:
    int minOpsBySort(int gaps, vector<int>& small, vector<int>& big) {
        
        sort(small.begin(), small.end());
        sort(big.begin(), big.end());
        
        int op = 0;
        int left = 0, right = big.size() -1;
        while (gaps >0) {
            
            int small_gaps = left < small.size() ? 6 - small[left] : 0;
            int big_gaps = right >= 0 ? big[right] - 1 : 0;
            
            if (small_gaps > big_gaps) {
                gaps -= small_gaps;
                left++;
            }else{
                gaps -= big_gaps;
                right--;
            }
            op++;
        }
        return op;
    }
    
    int minOpsByCnt1(int gaps, vector<int>& small, vector<int>& big) {
        int small_cnt[6] = {0} , big_cnt[6] = {0};
        for (auto& n : small) small_cnt[n-1]++;
        for (auto& n : big) big_cnt[n-1]++;
        
        int op = 0;
        int left = 0, right = 5; 
        
        while( gaps > 0 ) {
            while (left < 6 && small_cnt[left] == 0 ) left++;
            while ( right >=0 && big_cnt[right] == 0 ) right--;
            int small_gaps = left < 6 ? 6 - (left + 1) : 0;
            int big_gaps = right >= 0 ? right : 0;
            
            if (small_gaps > big_gaps) {
                gaps -= small_gaps;
                small_cnt[left]--;
            }else{
                gaps -= big_gaps;
                big_cnt[right]--;
            }
            op++;
        }
        return op;
    }
    
    int minOpsByCnt2(int gaps, vector<int>& small, vector<int>& big) {
        int cnt[6] = {0};
        for (auto& n : small) cnt[6-n]++;
        for (auto& n : big) cnt[n-1]++;
        
        int ops = 0;
        for (int i=5 ; i >= 0 && gaps > 0; i--) {
            if (cnt[i] == 0) continue;
            if (cnt[i] * i > gaps) {
                ops +=  (gaps / i  + (gaps % i ? 1:0) ) ;
                break;
            }
            gaps -= cnt[i] * i;
            ops += cnt[i];
        }
 
        return ops;
    }
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if ( len1 > 6*len2 || len2 > 6*len1) return -1;
        
        int sum1 = 0 , sum2 = 0;
        for (auto& n : nums1) sum1 += n;
        for (auto& n : nums2) sum2 += n;
        
        if (sum1 > sum2) {
            swap(sum1, sum2);
            swap(nums1, nums2);
        }
        int gaps = sum2 - sum1;
        if (gaps == 0) return 0;
        return minOpsByCnt2(gaps, nums1, nums2); //104ms
        return minOpsByCnt1(gaps, nums1, nums2); //108ms
        return minOpsBySort(gaps, nums1, nums2); //140ms
    }
};