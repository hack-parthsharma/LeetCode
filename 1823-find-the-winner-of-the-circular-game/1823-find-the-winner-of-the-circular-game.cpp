class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> persons(n);
        for(int i=0; i<n; i++) persons[i] = i + 1;
        
        for(int start=0; n>1; n--){
            start = (start + k -1) % n;
            persons.erase(persons.begin() + start);
            start = start %(n-1);
        }
        return persons[0];
    }
};