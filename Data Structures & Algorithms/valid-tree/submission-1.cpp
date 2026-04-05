class Solution {
public:
    bool dfs(int node, int parent, unordered_set<int>& visited, vector<vector<int>>& adj){
        // if already visited simply return false
        if(visited.count(node)){
            return false;
        }

        // visite current node
        visited.insert(node);
        // traverse all its neighbours
        for(int neigh : adj[node]){
            if(neigh == parent){
                continue;
            }

            // make next dfs call with neigh as node and current node as parent
            if(!dfs(neigh, node, visited, adj)){
                return false;
            }
        }

        // if cycle doesn't found return true
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        // to a graph a valid tree, it has no cycles + it is fully connected
        // If we ever reach a node that was already visited (and is not the parent) means cycle exists.
        // After dfs, if all nodes are visited, the graph is connected

        if(edges.size() > n - 1){
            return false;
        }

        // build tree in adjency list format
        vector<vector<int>>adj(n);
        for(const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        unordered_set<int>visited;
        // start with indx 0 node and parent -1
        if(!dfs(0, -1, visited, adj)){
            return false;
        }

        // if all nodes are visited and cycle doesn't found means, it valid tree
        return visited.size() == n;
    }
};
