class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // optimized version of bellman-ford
        // here instead of releaxing all edges every time, we:
        // only re-process nodes whose distance was actually improved
        // for this we can use a queue to propogate distance updates
        // efficiently, so whenever a node's shortest time decreases, its
        // neighbors might also get a shorter path so we push that node in que
        // which can be used in next iteration
        
        // create a weighted ordered graph
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto time : times){
            int u = time[0], v = time[1], wt = time[2];
            adj[u].push_back(make_pair(v, wt));
            // or we can use
            // adj[u].emplace_back(v, wt);
        }

        vector<int>dist(n+1, INT_MAX);
        dist[k] = 0;

        queue<pair<int,int>>que; 
        que.push({k,0});

        while(!que.empty()){
            auto [node, time] = que.front();
            que.pop();
            // If we already found a better path before skip
            // (this avoids unnecessary processing)
            if(dist[node] < time){
                continue;
            }

            // explore the neighbours
            for(auto [neigh, wt] : adj[node]){
                if(time + wt < dist[neigh]){
                    dist[neigh] = time + wt;
                    que.push({neigh, dist[neigh]});
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
