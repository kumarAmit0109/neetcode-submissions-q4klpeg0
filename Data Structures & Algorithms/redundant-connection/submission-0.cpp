class Solution {
public:
    bool dfs(int node, int parent, unordered_map<int, list<int>>&adj, vector<bool>&visit ){
        visit[node] = true;
        
        for(auto neigh : adj[node]){
            if(neigh == parent){
                continue;
            }
            if(!visit[neigh]){
                if (dfs(neigh, node, adj, visit)) {
                    return true;  
                }
            }else{
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // add edges one by one to graph and for each added edge 
        // make a call to the dfs fxn to detect whether its is
        // cycle or not, if cycle found then the new added edge is the
        // our answer

        int n = edges.size();
        unordered_map<int, list<int>>adj;

        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool>visit(n+1,false);
            // strt the dfs call for detecting cycle with node u
            if(dfs(u, -1, adj, visit)){
                return {u, v};
            }
        }
        return {};
    }
};
