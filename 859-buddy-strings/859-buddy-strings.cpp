class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        if (A.size()<2) return false;
        
        bool bRepeat = false;
        bool map[26] = {false};
        int idx[2], diffCnt=0;
        
        for (int i=0; i<A.size(); i++){
            if (map[A[i]-'a']) { bRepeat = true;}
            map[A[i]-'a']=true;
            if ( A[i] != B[i] ) {
                if (diffCnt>=2) return false;
                idx[diffCnt++] = i;
                
            }
        }
        //if A == B and there has repeated chars , then return true
        if (diffCnt==0 && bRepeat) return true;
        
        return (A[idx[0]] == B[idx[1]] && A[idx[1]] == B[idx[0]]);
        
    }
};