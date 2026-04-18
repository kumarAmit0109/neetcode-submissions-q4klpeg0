class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // simply use kahn's algo to detect cycle 
        unordered_map<int, list<int>>adj;
        vector<int>indegree(numCourses, 0);

        for(auto preq : prerequisites){
            indegree[preq[1]]++;
            adj[preq[0]].push_back(preq[1]);
        }

        queue<int>que;
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
            cnt++;
            for(int neig : adj[node]){
                indegree[neig]--;
                if(indegree[neig] == 0){
                    que.push(neig);
                }
            }
        }

        // if cnt is equal to number of courses means we can finish the
        // courses 
        return cnt == numCourses;
    }
};
