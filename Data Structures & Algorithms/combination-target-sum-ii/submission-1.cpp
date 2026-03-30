class Solution {
public:
    void solve(vector<int>& candidates, int target, int i, vector<int>& curr, int total, vector<vector<int>>& res){
        if(total == target){
            res.push_back(curr);
            return;
        }

        if(total > target || i == candidates.size()){
            return;
        }

        // include the current element in the list
        curr.push_back(candidates[i]);
        solve(candidates, target, i+1, curr, total + candidates[i], res);
        curr.pop_back();
        // move the i to the postion where if the duplicates of the curr elem exist 
        // so we can easily eleminate 
        while(candidates[i] == candidates[i+1]){
            i++;
        }
        // make a call with the excluding the curr elements as well as duplicates
        solve(candidates, target, i+1, curr, total, res);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        // initially total is 0 as well as indx is 0
        solve(candidates, target, 0, curr, 0, res);
        return res;
    }
};
