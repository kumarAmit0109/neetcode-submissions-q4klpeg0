class Solution {
public:
    void dfs(int node, int time, unordered_map<int, vector<pair<int, int>>>& adj, vector<int>& dist){
        // already found a faster way
        if (time >= dist[node]){
            return;
        }   
        dist[node] = time; // update shortest time
        for (auto& [nei, w] : adj[node]) {
            dfs(nei, time + w, adj, dist);  // explore neighbor with added travel time
        }
        
    }
             
             
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create a weighted ordered graph
        unordered_map<int, vector<pair<int,int>>>adj;

        for(auto time : times){
            int u = time[0], v = time[1], wt = time[2];
            adj[u].push_back(make_pair(v, wt));
            // or we can use
            // adj[u].emplace_back(v, wt);
        }

        vector<int>dist(n+1, INT_MAX);
        // using dfs find the mintime to take reach the signal from
        // src to each node
        // strt dfs with src node k nd time 0
        dfs(k, 0, adj, dist);
        // after that return the maximun time taken from the dist vector
        int res = *max_element(dist.begin()+1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
