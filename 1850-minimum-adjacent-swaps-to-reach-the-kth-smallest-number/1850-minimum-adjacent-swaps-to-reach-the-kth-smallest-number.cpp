class Solution {
private:
    // Refer to:
    // https://leetcode.com/problems/next-permutation/solution/
    void nextPermutation(string& num) {
        int i = num.size() - 2;
        while (i >= 0 && num[i + 1] <= num[i]) {
            i--;
        }
        if (i >= 0) {
            int j = num.size() - 1;
            while (j >= 0 && num[j] <= num[i]) {
                j--;
            }
            swap(num[i], num[j]);
        }
        reverse(num, i + 1);
    }

    void reverse(string& num, int start) {
        int i = start, j = num.size() - 1;
        while (i < j) {
            swap(num[i], num[j]);
            i++;
            j--;
        }
    }


public:
    int getMinSwaps(string num, int k) {
        string pnum = num;
        while(k--) {
            nextPermutation(pnum);
        }
        //cout << num << endl << pnum << endl;
        int result = 0;
        for(int i = 0; i < num.size(); i++) {
            if (num[i] == pnum[i]) continue;
            for(int j = i + 1; j < num.size(); j++) {
                if(num[i] != pnum[j]) continue;
                //cout << "j=" << j << ", i=" << i << endl;
                result += j - i;
                
                //shift the string
                char c = pnum[j];
                for (int k = j; k > i; k--) {
                    pnum[k] = pnum[k-1];
                }
                pnum[i] = c;
                //cout << pnum << endl;
                break;
            }
        }
        //cout << endl;
        return result;
    }
};