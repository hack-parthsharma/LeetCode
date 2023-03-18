 class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int,int>myMap;
        for(int i=0;i<A.size();i++){
            myMap[A[i]]++;
        }
        for(auto x:myMap){
            if((x.second)==(A.size()/2)){
                return x.first;
            }
        }
        return 0;
    }
};