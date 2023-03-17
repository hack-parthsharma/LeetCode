class Solution {
public:
    int getWinner(vector<int>& arr, int k) { 
        
        int left=0, right=1;
        
        int max = arr[left] > arr[right] ? arr[left] : arr[right];
        int winner; 
        int win_times = 0;
        
        while( right < arr.size())  {

            //if left < right,  the move the `left` to the `right`
            if ( arr[left] < arr[right] ) {
                left = right;
            }
            // move the `right` to next element
            right++;
            //record current round winner.
            int w = arr[left];            
            
            if (w == winner) {
                //if winner is same, count++
                win_times++; 
            }else{
                // if winner is new number, reset the count.
                winner = w;
                win_times = 1;
            }
            
            // if the time of win equal K, return winner. 
            if (win_times >= k) return winner;
            
            // find the max element of this array, if k > arr.size() then return this
            if (max < arr[right]) max = arr[right];
        }
        
        return max;
    }
};