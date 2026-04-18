class Solution {
public:
    bool dfs(int node, unordered_map<int, list<int>>& adj, vector<int>& vis, vector<int>& pathVis) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(nei, adj, vis, pathVis)) {
                    return true;
                }
            } 
            else if (pathVis[nei]) {
                return true; // cycle found
            }
        }

        pathVis[node] = 0; // backtrack
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, list<int>> adj;

        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]); // important direction
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) {
                    return false;
                }
            }
        }
        return true;
    }
};