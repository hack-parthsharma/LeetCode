class Order {
public:
    int price;
    int amount;
};

enum COMP { GREATER, LESS };

template <COMP op>
class OrderComp {
public:
    bool operator() (const Order& lhs, const Order& rhs) {
        if (op == GREATER) {
            return lhs.price > rhs.price;
        }
        return lhs.price < rhs.price;
    }
};


class Solution {
private:
    template<typename T1, typename T2>
    void processOrder(T1& q1, T2& q2, COMP op, int price, int amount, string n1="q1", string n2="q2") {
        if (q2.size() == 0) {
            q1.push(Order{price, amount});
            return;
        }
        
        while(!q2.empty() && amount > 0  ){
            Order order = q2.top(); 
            if (op == GREATER && order.price > price ) break;
            if (op == LESS && order.price < price) break;

            q2.pop();
            //cout << "=> deQueue("<< n2 << "): " << order.price << ", "<< order.amount << endl;

            int amt = min(order.amount, amount);
            order.amount -= amt;
            amount -= amt;
            if (order.amount > 0) {
                //cout << "<= enQueue("<< n2 <<"): " << order.price << ", "<< order.amount << endl;
                q2.push(order);
            }
        }
        if (amount > 0) {
            //cout << "<= enQueue("<< n1 <<"): " << price << ", "<< amount << endl;
            q1.push(Order{price, amount});
        }
    }
    
    template<typename T>
    void countQ(T& q, int& amount){
        while(!q.empty()) {
            amount = (amount + q.top().amount) % 1000000007;
            q.pop();
        }
    }
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        
        priority_queue<Order, vector<Order>, OrderComp<GREATER>> sell;
        priority_queue<Order, vector<Order>, OrderComp<LESS>> buy;
        
        
        for (auto& order : orders) {
            int& price = order[0];
            int& amount = order[1];
            
            if (order[2] == 0)  { //buy order
                processOrder(buy, sell, GREATER, price, amount, "buy", "sell");
            }else { // sell order
                processOrder(sell, buy, LESS, price, amount, "sell", "buy");
            }
        }
        
        int amount = 0;
        countQ(sell, amount);
        countQ(buy, amount);
        return amount ;
    }
};