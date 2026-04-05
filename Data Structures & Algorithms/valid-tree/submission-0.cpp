class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // to a graph a valid tree, it has no cycles + it is fully connected
        // If we ever reach a node that was already visited (and is not the parent) means cycle exists.
        // After BFS, if all nodes are visited, the graph is connected

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
        // queue store {current node, parent}
        queue<pair<int,int>>que;
        // initially parent of current node is -1
        que.push({0, -1});
        visited.insert(0);

        while(!que.empty()){
            auto [node, parent] = que.front();
            que.pop();

            // traverese all the neighbours
            for(int neigh : adj[node]){
                if(neigh == parent){
                    continue;
                }

                // if neigh already visited + its not parent then cycle exist
                // so simply return false
                if(visited.count(neigh)){
                    return false;
                }

                visited.insert(neigh);
                que.push({neigh, node});
            }
        }

        // if all nodes are visited and cycle doesn't found means, it valid tree
        return visited.size() == n;
    }
};
