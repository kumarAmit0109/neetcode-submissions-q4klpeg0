class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // use the idea that nodes with one indegree can not be part of
        // cycle so, simply use kahn's style algo to start removing the 
        // nodes which are having 1 indegree until we are left with the
        // nodes having more than 1 indegree, which means we are left
        // with cycle only, now traverse the edge in backward direction and
        // find the first edge which is part of cycle nd it is our answer
        int n = edges.size();
        unordered_map<int, list<int>>adj;
        vector<int>indegree(n+1, 0);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<int>que;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 1){
                que.push(i);
            }
        }

        while(!que.empty()){
            int node = que.front();
            que.pop();
            // mark this node as removed so can not be able to visit this node
            // again
            indegree[node]--;

            for(int nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei] == 1){
                    que.push(nei);
                }
            }
        }

        // at this point only cycle nodes have indegree >= 2
        // traverse edges from back to find the last edge where
        // both endpoints are still part of the cycle
        // that edge is the redundant one we need to remove
        for(int i = edges.size() - 1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            // indegree >= 2 means node is part of cycle
            if(indegree[u] >= 2 && indegree[v] >= 2){
                return {u, v};
            }
        }
        return {};
    }
};
