class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // using bellman ford algorithm
        vector<int>dist(n+1, INT_MAX);
        // initialize src dist at 0
        dist[k] = 0;

        // apply bellman ford condn n-1 times to all edges
        for(int i = 0; i < n-1; i++){
            for(const auto& time : times){
                int u = time[0];
                int v = time[1];
                int wt = time[2];

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
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
