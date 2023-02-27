class Solution {
public:
    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(n+1);
        unordered_map<int, unordered_map<int, int>> shared;
        for (auto& e : edges) {
            int x = e[0], y = e[1];
            degree[x]++;
            degree[y]++;
            shared[min(x,y)][max(x,y)]++;
        }

        vector<int> sorted = degree;
        sort(sorted.begin(), sorted.end());

        vector<int> result;
        for (auto& q : queries) {
            int cnt = 0;
            int left = 1, right = n;
            //Assuming all of the nodes are independent.
            while( left < right ) {
                if (q < sorted[left] + sorted[right] ) {
                    cnt += (right - left);
                    right--;
                }else {
                    left++;
                }
            }
            //check all of pair they are connected.
            for (int i = 1; i <= n; i++){
                for (auto [j, shared_edges] : shared[i]) {
                    int all_edges = degree[i] + degree[j];
                    // `q < all_edges`  ==> this pair had been counted before!
                    // `q >= all_edges - shared_edges` ==> this pair should be counted!
                    if ( q < all_edges && q >= all_edges - shared_edges ) {
                        cnt--;
                    }
                }
            }
            result.push_back(cnt);
        }
        return result;
    }
};
