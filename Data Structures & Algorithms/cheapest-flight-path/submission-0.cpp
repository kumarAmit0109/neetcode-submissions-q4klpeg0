class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 5, INF));

        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }

        dist[src][0] = 0;
        priority_queue<tuple<int, int, int>,
                       vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.emplace(0, src, -1);

        while (!minHeap.empty()) {
            auto [cst, node, stops] = minHeap.top();
            minHeap.pop();
            if (node == dst) return cst;
            if (stops == k || dist[node][stops + 1] < cst) continue;
            for (auto& [nei, w] : adj[node]) {
                int nextCst = cst + w;
                int nextStops = stops + 1;
                if (dist[nei][nextStops + 1] > nextCst) {
                    dist[nei][nextStops + 1] = nextCst;
                    minHeap.emplace(nextCst, nei, nextStops);
                }
            }
        }
        return -1;
    }
};