class Solution {

public:
    vector<int> minOperations(string boxes) {
        vector<int> result(boxes.size());
        //minOperations01(boxes, result); //128ms
        minOperations02(boxes, result); //4s
        return result;
    }
    
    void minOperations01(string& boxes, vector<int>& result ) {
        vector<int> balls;
        for(int i=0; i<boxes.size(); i++) {
            if(boxes[i] == '1') balls.push_back(i);
        }
        
        for (int i=0; i<boxes.size(); i++) {
            int steps = 0;
            for (int j=0; j<balls.size(); j++) {
                steps += abs(balls[j] - i);
            }
            result[i] = steps;
        }
    }
    void minOperations02(string& boxes, vector<int>& result ) {
        //from left to right
        for(int i=0, ops=0, balls=0; i< boxes.size(); i++) {
            result[i] += ops;
            balls += (boxes[i] == '1' ? 1 : 0);
            ops += balls;
        }
        //from right to left
        for(int i=boxes.size()-1, ops=0, balls=0; i>=0; i--) {
            result[i] += ops;
            balls += (boxes[i] == '1' ? 1 : 0);
            ops += balls;
        }
    }
};