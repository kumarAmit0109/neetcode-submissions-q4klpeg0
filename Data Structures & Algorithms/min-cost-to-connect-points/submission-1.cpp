class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // build a graph where each pair of points has an edges with weight
        // is equal to manhattan distance
        int n = points.size();
        unordered_map<int, vector<pair<int, int>>>adj;
        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        // use unordered set to keep track of visited nodes
        unordered_set<int> visit;
        // use min heap to pick the node with the min associated weight egde
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>minHeap;

        // start with node 0
        minHeap.push({0, 0});

        while((visit.size() < n) && !minHeap.empty()){
            auto curr = minHeap.top();
            minHeap.pop();

            int cost = curr.first;
            int node = curr.second;
            // if its already visited then continue
            // else add cost to result and explore the neighbour
            if(visit.count(node)){
                continue;
            }

            res += cost;
            visit.insert(node);
            for(auto neigh : adj[node]){
                int neighCost = neigh.first;
                int neighIndex = neigh.second;
                // Only consider unvisited nodes
                if(!visit.count(neighIndex)){
                    minHeap.push({neighCost, neighIndex});
                }
            }
        }
        return res;                         
    }
};
