class Solution {
private:
    template<typename T>
    void print_queue(T q) { // NB: pass by value so the print uses a copy
        while(!q.empty()) {
            auto [profit, c] = q.top();
            auto [pass, total] = c;
            cout <<  "[" << profit << " - " << pass << ", " << total <<"], ";
            q.pop();
        }
        cout << '\n';
    }

    //calculating ratio
    double ratio(double pass, double total) {
        return pass / total;
    }
    //calculating the profit
    double profit(double pass, double total) {
        return ratio(pass + 1, total + 1)  - ratio(pass, total);
    }

public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<pair<double, pair<int,int>> > q;
        
        double total_ratio = 0;
        int cnt = 0;
        for (auto& c : classes) {
            total_ratio += ratio(c[0], c[1]);
            q.push({profit(c[0], c[1]), {c[0],c[1]}});
        }
        //print_queue(q);
        
        while(extraStudents--){
            auto [added_profit, c] = q.top();
            auto [pass, total] = c;
            q.pop();
            
            total_ratio += added_profit;
            pass++; total++;
            q.push({profit(pass, total), {pass, total}});
        }
        //print_queue(q);
        
        return total_ratio / classes.size();
    }
};
