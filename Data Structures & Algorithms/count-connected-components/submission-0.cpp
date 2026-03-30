class Solution {
public:
    void solve(int i, vector<vector<int>>& adj, vector<int>& visited) {
        queue<int> q;
        q.push(i);
        visited[i] = 1;

        while (!q.empty()) {
            int frnt = q.front();
            q.pop(); // Don't forget to pop the front element.
            for (auto neigh : adj[frnt]) {
                if (!visited[neigh]) {
                    q.push(neigh);
                    visited[neigh] = 1;
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        // Initialize adjacency list with size n.
        vector<vector<int>> adj(n);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> visited(n, 0); // Keeps track of visited nodes.
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) { // Only explore if the node hasn't been visited.
                count++;
                solve(i, adj, visited);
            }
        }

        return count;
    }
};
