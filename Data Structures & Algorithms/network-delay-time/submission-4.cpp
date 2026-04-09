class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create a distance matrix
        // if both distance are INT_MAX then in addition of them may cause
        // overflow to avoid this use INT_MAX?2 as the initiall distance
        int inf = INT_MAX / 2;
        vector<vector<int>>dist(n, vector<int>(n, inf));

        // prepare distance matrix for floyd warshall algorithm
        // distance to self is zero
        for(int i = 0; i < n; i++){
            dist[i][i] = 0;
        }

        // fill the given edges
        for(auto& time : times){
            int u = time[0] - 1;
            int v = time[1] -1;
            int wt = time[2];
            dist[u][v] = wt;
        }

        // apply floyd warshall algorithm
        // Goal: Find shortest path between every pair (i → j)
        // Try every node as an intermediate (middle) node
        for(int mid = 0; mid < n; mid++){

            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    // from going i to j via mid if we get shortest dist than
                    // update it 
                    dist[i][j] = min(dist[i][j], dist[i][mid] + dist[mid][j]);
                }
            }
        }

        int res = *max_element(dist[k-1].begin(), dist[k-1].end());
        return res == inf ? -1 : res;

    }

};
