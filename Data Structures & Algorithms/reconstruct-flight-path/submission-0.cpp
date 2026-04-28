class Solution {
   public:
    bool dfs(const string& src, vector<string>& res, unordered_map<string, vector<string>>& adj,  int targetLen) {
        // if itinerary length matches required length then solution found
        // simply return true
        if (res.size() == targetLen) {
            return true;
        }

        // if no outgoing flights from current airport then backtrack
        if (adj.find(src) == adj.end()) {
            return false;
        }

        // copy current adjacency list for safe iteration
        vector<string> temp = adj[src];
        for (int i = 0; i < temp.size(); ++i) {
            string v = temp[i];                    // next destination
            adj[src].erase(adj[src].begin() + i);  // remove edge (use ticket)
            res.push_back(v);                      // add destination to itinerary

            // recursive DFS call
            if (dfs(v, res, adj, targetLen)){
                return true;
            } 

            // Backtrack: restore edge and remove destination from itinerary
            adj[src].insert(adj[src].begin() + i, v);
            res.pop_back();
        }
        // if still no valid itinerary found then return false
        return false; 
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // build adjacency list: each departure airport maps to a list of arrival airports
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]];  // ensure every departure airport is in the map
        }

        // sort tickets lexicographically to guarantee smallest lexical order traversal
        sort(tickets.begin(), tickets.end());
        for (auto& ticket : tickets) {
            adj[ticket[0]].push_back(ticket[1]);  // add destination to adjacency list
        }

        // result itinerary starts with "JFK"
        vector<string> res = {"JFK"};
        // perform DFS to construct itinerary of length = number of tickets + 1
        dfs("JFK", res, adj, tickets.size() + 1);
        return res;
    }
};
