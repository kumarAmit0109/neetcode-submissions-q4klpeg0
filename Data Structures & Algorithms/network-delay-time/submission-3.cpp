class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // use dijkstra's algo to find the shortest time from the src node

        // create a weighted ordered graph
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto time : times){
            int u = time[0], v = time[1], wt = time[2];
            adj[u].push_back(make_pair(v, wt));
           
        }

        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;
        minHeap.push({0, k});

        while(!minHeap.empty()){
            auto [wt, node] = minHeap.top();
            minHeap.pop();

            // If we already found a better path before skip
            // (this avoids unnecessary processing)
            // if(dist[node] < wt){
            //     continue;
            // }

            // explore neighbour nodes 
            for(auto neigh : adj[node]){
                int neighNode = neigh.first;
                int wt = neigh.second;

                if(dist[node] + wt < dist[neighNode]){
                    dist[neighNode] = dist[node] + wt;
                    minHeap.push({dist[neighNode], neighNode});
                }
            }

        }

        int maxDist = *max_element(dist.begin()+1 , dist.end());

        if(maxDist == INT_MAX){
            return -1;
        }else{
            return maxDist;
        }

    }
};
