class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // sort the points vector based on the distance from the origin 
        // we can use square of distances for comparision 
        sort(points.begin(), points.end(), [](const auto& a, const auto& b){
            return ((a[0]*a[0] + a[1]*a[1]) < (b[0]*b[0] + b[1]*b[1]));
        });

        // now return the first k points from the sorted list
        vector<vector<int>>result(points.begin(), points.begin()+k);
        return result;
    }
};
