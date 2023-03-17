class Solution {
private:
    void print(vector<vector<int>>& boxes) {
        cout << "{ ";
        for(int i=0; i<boxes.size()-1; i++){
            cout << "[" << boxes[i][0] << ","<< boxes[i][1] << "], ";
        }
        int i=boxes.size()-1;
        cout << "[" << boxes[i][0] << ", "<< boxes[i][1] << "] } "<< endl;
    }
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), 
             [&](vector<int>& lhs, vector<int>& rhs){return lhs[1] > rhs[1]; });
        //print(boxTypes);
        int units = 0;
        for(auto& box : boxTypes) {
            if (truckSize >= box[0]) {
                units += box[0] * box[1];
            }else{
                units += truckSize * box[1];
            }
            truckSize -= box[0];
            if (truckSize <= 0 ) break;
        }
        return units;
    }
};