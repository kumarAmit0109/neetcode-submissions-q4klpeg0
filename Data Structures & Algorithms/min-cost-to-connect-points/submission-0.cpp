#include <array>
class DisjointSetUnion {
public:
    vector<int> parent, rank;

    // Constructor: initialize DSU
    DisjointSetUnion(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        // Initially, every node is its own parent
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    // Find with Path Compression
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        // Path compression
        return parent[node] = findParent(parent[node]);
    }

    // Union by Rank
    bool unionSet(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);

        // If already in same set → cycle
        if (parentU == parentV) return false;

        // Attach smaller rank tree under larger
        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } 
        else if (rank[parentU] > rank[parentV]) {
            parent[parentV] = parentU;
        } 
        else {
            parent[parentV] = parentU;
            rank[parentU]++; // increase rank if same
        }

        return true; // union happened
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // Create DSU
        DisjointSetUnion dsu(n);

        // Store edges as {distance, u, v}
        vector<array<int, 3>> edges;

        // Build all edges (complete graph)
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);

                edges.push_back({dist, i, j});
            }
        }

        // Sort edges by distance (Kruskal's algo)
        sort(edges.begin(), edges.end());

        int res = 0;
        int edgesUsed = 0;

        // Process edges
        for (auto [dist, u, v] : edges) {
            // If u and v are not connected → include edge
            if (dsu.unionSet(u, v)) {
                res += dist;
                edgesUsed++;
                // Optimization: stop when MST is formed
                if (edgesUsed == n - 1) break;
            }
        }
        return res;
    }
};