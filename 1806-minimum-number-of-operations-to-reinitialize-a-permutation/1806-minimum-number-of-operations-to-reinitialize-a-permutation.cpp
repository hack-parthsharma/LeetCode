class Solution {
private: 
    bool check(vector<int>& a) {
        for(int i=0; i<a.size(); i++) {
            if (a[i] != i) return false;
        }
        return true;
    }
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        vector<int> arr(n);
        for(int i=0; i<n; i++) {
            perm[i] = i;
        }
        int cnt = 0;
        while(1){
            cnt++;
            for(int i=0; i<n; i++) {
                if (i%2==0) arr[i] = perm[i / 2];
                else arr[i] = perm[n / 2 + (i - 1) / 2];
            }
            if (check(arr)) break;
            perm = arr;
        }
        
        return cnt;
        
    }
};