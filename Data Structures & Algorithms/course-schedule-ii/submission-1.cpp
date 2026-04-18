class Solution {
public:
    void dfs(int i, unordered_map<int, list<int>>&adj, vector<int>& indegree, vector<int>& topo){
        topo.push_back(i);
        // By doing indegree[i]-- immediately, you ensure that if DFS ever encounters this course
        // again through another path, its indegree won’t still be zero. This prevents multiple 
        // DFS calls from pushing the same course into topo more than once.
        indegree[i]--;
        for(int nei : adj[i]){
            indegree[nei]--;
            if(indegree[nei] == 0){
                dfs(nei, adj, indegree, topo);
            }
        }
    }
    vector<int> findOrder (int numCourses, vector<vector<int>>& prerequisites) {
        // simply use kahn's algo to detect order or 
        // its simply the topological sort order
        unordered_map<int, list<int>>adj;
        vector<int>indegree(numCourses, 0);

        // [a,b] simply means the we have to take course b before a 
        // means edge is from b to a not a to b
        for(auto preq : prerequisites){
            indegree[preq[0]]++;
            adj[preq[1]].push_back(preq[0]);
        }

        vector<int>topo;
        // use dfs call to handle this queue part 
        for(int i = 0 ; i < numCourses; i++){
            // if indegree is 0, simply push it into que
            if(indegree[i] == 0){
                dfs(i, adj, indegree, topo);
            }
        }

        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};
