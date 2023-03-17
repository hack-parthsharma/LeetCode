class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char key[] ="ab";
        if (y > x) { key[0] = 'b'; key[1]='a';}
        
        int high = max(x,y);
        int low = min(x,y);
        
        //greedy for high score
        int score = 0;
        stack<char> left_stack;
        for (int i=0; i<s.size(); i++) {
            char c = s[i];
            if (  left_stack.empty()  ||  //stack is empty, just push directly
                 ( c != key[0] && c != key[1] ) ) { // not the score char, just tpush cirectory
                left_stack.push(c);
                continue;
            }

            // if we meet the high score pattern
            if ( c == key[1] && left_stack.top() == key[0]){
                //cout << key << endl;
                left_stack.pop();
                score += high;
                continue;
            }
            left_stack.push(c);
        }
        
        //process the low score
        stack<char> right_stack;
        while(!left_stack.empty()) {
            char c = left_stack.top();  left_stack.pop();
            if (right_stack.empty() || c != key[0] && c != key[1]) {
                right_stack.push(c);
                continue;
            }
            // if we meet the low score pattern
            if ( c == key[1] && right_stack.top() == key[0]){
                right_stack.pop();
                score += low;
                continue;
            }
            
            right_stack.push(c);
        }
        return score;
    }
};