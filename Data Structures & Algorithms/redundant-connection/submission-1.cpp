class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited, unordered_set<int>& cycle, int& cycleStart){
        // if node is already visited means we found cycle
        if(visited[node]){
            cycleStart = node;
            return true;
        }

        visited[node] = true;
        // explore neighbours
        for(int nei : adj[node]){
            if(nei == parent){
                continue;
            }
            if(dfs(nei, node, adj, visited, cycle, cycleStart)){
                // if cycle detected simply insert the node in cyclic set
                if(cycleStart != -1){
                    cycle.insert(node);
                }
                // if node is the start node of cycle so reset the cycleStart
                // to stop collecting more nodes into cycle set
                if(node == cycleStart){
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // here we simply call dfs nd tries to find the cyclic loop or
        // collect the nodes which are part of cycle
        // after we found the cyclic set of nodes, then we start traversing the
        // edge vector nd find the the first edge which are part of this cyclic set
        // that edge is our ans

        vector<bool>visited(n+1, false);
        unordered_set<int>cycle;
        int cycleStart = -1;
        // start dfs with first node nd parent -1
        dfs(1, -1, adj, visited, cycle, cycleStart);

        // after cyclic set found travese in reverse direction
        for(int i = edges.size()-1; i >= 0; i--){
            int u = edges[i][0];
            int v = edges[i][1];
            if(cycle.count(u) && cycle.count(v)){
                return {u, v};
            }
        }
        return {};

    }
};
