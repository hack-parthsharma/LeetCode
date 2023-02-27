class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double,int>> vec;
        for(int i=0;i<points.size();i++){//for loop for calculating distances and pushing it back in the vector
            double distance = std::sqrt(std::pow(points[i][0], 2)+std::pow(points[i][1], 2));
            vec.push_back(make_pair(distance,i));
        }
        sort(vec.begin(), vec.end());//sorting the vector according to distances
        vector<vector<int>> f;//final points vector
        for(int i=0;i<K;i++){
            f.push_back(points[vec[i].second]);//pushing in the points accordingly
        }
        return f;
    }
};