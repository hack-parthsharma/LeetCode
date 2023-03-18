class RecentCounter {
public:
    RecentCounter() {

    }

    int ping(int t) {
        req.push_back(t);
        return req.size() - binary_search(t-3000);
    }
private:
    vector<int> req;
    int binary_search(int x) {
        int low=0, high=req.size()-1;
        while(low < high) {
            int mid = low + (high -low) / 2;
            if ( req[mid] == x ) return mid;
            if ( req[mid] < x ) low = mid + 1;
            else high = mid - 1;
        }
        cout << "x="  << x << "\tlow=" << low << endl;
        return x > req[low] ? low+1 : low ;
    }
};

/**
 * Your R
ecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */