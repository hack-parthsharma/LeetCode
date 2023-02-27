class Solution {
public:
    bool verify(vector<int>& dist, double hour, int speed) {
        double t = 0;
        int n = dist.size();
        for (int i=0; i<n-1; i++){
            t += (dist[i] + speed -1) / speed;
        }
        t += (double)dist[n-1]/speed;
        return t <= hour;
    }
    
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (hour <= n-1) return -1;
        
        int low = 1, high = 1e7;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (verify(dist, hour, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};
