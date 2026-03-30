class Solution {
public:
    vector<vector<int>> res;   // stores all valid unique combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Step 1: Sort the array
        // sorting keeps the Skiping duplicates easily and Stop early when sum exceeds target (pruning)
        sort(candidates.begin(), candidates.end());
        // initially indx 0, path empty, curr 0    
        dfs(0, {}, 0, candidates, target);
        return res;
    }

    void dfs(int idx, vector<int> path, int cur, vector<int>& candidates, int target) {

        // If current sum equals target → valid combination found
        if (cur == target) {
            res.push_back(path);   
            return;               
        }

        // Try every number starting from current index
        for (int i = idx; i < candidates.size(); i++) {

            // Duplicate control
            // If this number is same as previous
            // and we are at the same recursion level,
            // skip it to avoid duplicate combinations
            if (i > idx && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Pruning (early stopping)
            // Since array is sorted,
            // if adding this number exceeds target,
            // no need to check further numbers
            if (cur + candidates[i] > target) {
                break;
            }

            // include the current number nd make call by including it
            path.push_back(candidates[i]);
            // because each number can be used only once
            dfs(i + 1, path, cur + candidates[i], candidates, target);

            // Backtrack 
            // Remove last added number to try next possibilities
            path.pop_back();
        }
    }
};