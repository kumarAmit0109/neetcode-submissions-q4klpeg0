class Solution {
   public:
   bool dfs(int i, unordered_map<int, vector<int>>& prereq, unordered_set<int>& visited, unordered_set<int>& isCalled, vector<int>& ans ){

        visited.insert(i);
        isCalled.insert(i);
        for(int pre : prereq[i]){
            // prereq not visited yet so recurse into it
            if(!visited.count(pre)){
                if(!dfs(pre, prereq, visited, isCalled, ans)){
                    return false;
                }
            }else{
                // prereq already visited then check if it's on CURRENT path
                // if yes which means cycle detected, so return false 
                // we are not able to visit all courses
                if(isCalled.count(pre)){
                    return false;
                }
            }
        }
        // backtrack
        isCalled.erase(i);
        ans.push_back(i);
        return true;
   }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create a prerequisites map
        unordered_map<int, vector<int>> prereq;
        for (const auto& pair : prerequisites) {
            prereq[pair[0]].push_back(pair[1]);
        }

        vector<int> ans;
        unordered_set<int> visited;
        unordered_set<int> isCalled;

        for (int i = 0; i < numCourses; i++) {
            // if cycle detected simply nd not able to complete
            // all course then simply return empty result
            if (!visited.count(i)) {
                if (!dfs(i, prereq, visited, isCalled, ans)) {
                    return {};
                }
            }
        }
        return ans;
    }
};
