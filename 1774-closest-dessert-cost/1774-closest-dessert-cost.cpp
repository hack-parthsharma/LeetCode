class Solution {
private:
    int abs_min (int x, int y, int z) {
        return  abs_min(x, abs_min(y, z));
    }
    // compare the absolute value and return the min one
    // if their absolute value are equal, return the positive one.
    int abs_min(int x, int y) {
        int ax = abs(x);
        int ay = abs(y);
        if (ax == ay) return max(x, y);
        return ax < ay ? x : y;
    }
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {

        int min_gap = INT_MAX;
        for (auto& base : baseCosts) {
            int gap = closetToppingCost(toppingCosts, target - base, 0);
            min_gap = abs_min(min_gap, gap);
        }
        
        return target - min_gap;
    }
    
    int closetToppingCost(vector<int>& costs, int target, int idx ){
    
        if (idx >= costs.size()) return target;

        // three options: not slect, select once & select twice
        int select_none  = closetToppingCost(costs, target, idx+1);
        int select_once  = closetToppingCost(costs, target - costs[idx], idx+1);
        int select_twice = closetToppingCost(costs, target - 2*costs[idx], idx+1);
        
        return abs_min(select_none, select_once, select_twice);
    }
    
};