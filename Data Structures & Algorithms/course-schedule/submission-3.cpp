class Solution {
public:

    bool dfs(int node, unordered_map<int, vector<int>>& preMap, unordered_set<int>& visited) {
        // If the node is already in the current DFS path,
        // we found a cycle so we cannot finish courses
        if (visited.count(node)) {
            return false;
        }

        // If the course has no prerequisites,
        // it can be completed successfully
        if (preMap[node].empty()) {
            return true;
        }

        // mark the current node as visited in the current recursion path
        visited.insert(node);
        // recursively check all prerequisites
        for (int pre : preMap[node]) {
            if (!dfs(pre, preMap, visited)) {
                // if any prerequisite leads to a cycle,
                // return false immediately
                return false;
            }
        }

        // backtrack: remove the node from current DFS path
        visited.erase(node);

        // optimization:
        // Once a course is confirmed cycle-free,
        // clear its prerequisites to avoid re-checking
        preMap[node].clear();

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // build a prerequisities map where each course points to its 
        // prerequisites
        unordered_map<int, vector<int>> preMap;
        // use set to keep track of visited node
        unordered_set<int> visited;

        // Initialize all courses with empty prerequisite lists
        for (int i = 0; i < numCourses; i++) {
            preMap[i] = {};
        }

        // Build the prerequisite graph
        // prereq[0] depends on prereq[1]
        for (const auto& prereq : prerequisites) {
            preMap[prereq[0]].push_back(prereq[1]);
        }

        // Run DFS for each course
        // This ensures disconnected components are also checked
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i, preMap, visited)) {
                return false; // Cycle detected
            }
        }

        // All courses can be completed
        return true;
    }
};