class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // priority_queue puts the element on top for which comparator returns false most of the time
        auto comp = [](const vector<int>& a, const vector<int>& b){
            return ((a[0]*a[0] + a[1]*a[1]) > (b[0]*b[0] + b[1]*b[1]));
        };

        // priority_queue (heap) with a custom comparator (lambda)
        // priority_queue<data_type, container_type, comparator> name(comparator);
        priority_queue<vector<int>, vector<vector<int>>, decltype(comp)>minHeap(comp);

        for(const auto& point : points){
            minHeap.push({point[0], point[1]});
        }

        vector<vector<int>>result;
        for(int i = 0; i < k; i++){
            result.push_back(minHeap.top());
            minHeap.pop();
        }

        return result;
    }
};
