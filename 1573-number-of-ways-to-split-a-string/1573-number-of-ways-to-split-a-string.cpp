#define mod (long long)(1e9+7)
#define ll long long
class Solution {
public:
    int numWays(string s) {

        int n = s.size();

        vector<int> pre(n),suf(n),last(n);
        int count=0;

        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                count++;
            }
            pre[i]=count;
        }

        // check if it can't be divided into three parts
        if(count%3!=0)
            return 0;

        int k  = count/3;
        count=0;
        int t=0;

        for(int i=n-1;i>=0;i--){
            if(s[i]=='1')
                count++;
            suf[i]=count;
        }

        count=0;

        for(int i=n-1;i>=0;i--){

            if(suf[i]==k)
                count++;
            last[i]=count;
        }

        ll res=0;

        for(int i=0;i<n-1;i++){

            if(pre[i]==k){

                if(k!=0)
                    res= (res+last[i+1])%mod;
                else
                    res=(res+last[i+1]-1)%mod;
            }
        }

        return res;
    }
};
