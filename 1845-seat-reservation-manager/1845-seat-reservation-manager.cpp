class SeatManager {
private:
    set<int> idle;
public:
    SeatManager(int n) {
        for(int i=1; i<=n; i++) {
            idle.insert(i);
        }
    }
    
    int reserve() {
        auto it = idle.begin();
        auto seat = *it;
        idle.erase(it);
        return seat;
    }
    
    void unreserve(int seatNumber) {
        idle.insert(seatNumber);
    }
};
