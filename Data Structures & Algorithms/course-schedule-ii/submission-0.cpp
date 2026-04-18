class Solution {
public:
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

        queue<int>que;
        vector<int>topo;
        for(int i = 0 ; i < numCourses; i++){
            // if indegree is 0, simply push it into que
            if(indegree[i] == 0){
                que.push(i);
            }
        }

        int cnt = 0;

        while(!que.empty()){
            int node = que.front();
            que.pop();
            // cnt++;
            topo.push_back(node);
            for(int neig : adj[node]){
                indegree[neig]--;
                if(indegree[neig] == 0){
                    que.push(neig);
                }
            }
        }

        // if cnt is equal to number of courses means we can finish the
        // courses 
        if(topo.size() == numCourses){
            return topo;
        }
        return {};
    }
};
