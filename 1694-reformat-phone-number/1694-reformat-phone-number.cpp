class Solution {
public:
    string reformatNumber(string number) {
        string result;
        for(int i=0, cnt=0; i<number.size(); i++){
            if(number[i] == ' ' or number[i] == '-') continue;
            result += number[i] ;
            cnt++;
            if (cnt % 3 == 0) result += '-';
        }
        
        int end = result.size()-1;
        if (result[end] == '-') result.erase(end, 1);
        if (result[end-1] == '-') swap(result[end-2] , result[end-1]);
        return result;
    }
};
