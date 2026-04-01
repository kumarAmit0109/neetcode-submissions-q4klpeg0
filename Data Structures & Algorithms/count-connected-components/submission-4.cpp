class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited) {
        visited[node] = true;

        for(int neigh : adj[node]){
            if(!visited[neigh]){
                dfs(neigh, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // create an adjacency list of given graph
        vector<vector<int>>adj(n);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // create a visited vector to keep track of visited nodes
        vector<int>visited(n, 0);
        int count = 0;

        // we simply do dfs traveral nd after completion of  every 
        // complete traversal we increase the count;
        
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                count++;
                dfs(i, adj, visited);
            }
        }
        return count;
    }
};
