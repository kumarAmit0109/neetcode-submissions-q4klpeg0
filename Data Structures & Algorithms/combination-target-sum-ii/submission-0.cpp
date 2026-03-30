class Solution {
public:
    void generateSubsets(vector<int>& candidates, int target, int i, vector<int>& curr, int total,  set<vector<int>>& res){
        // if total is sum store it nd return
        if(total == target){
            res.insert(curr);
            return;
        }

        if(total > target || i == candidates.size()){
            return;
        }

        // include curr element
        curr.push_back(candidates[i]);
        generateSubsets(candidates, target, i+1, curr, total+candidates[i], res);

        // exclude curr element
        curr.pop_back();
        generateSubsets(candidates, target, i+1, curr, total, res);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // consider set to store ans so that no duplicate ans occurs
        set<vector<int>>res;
        sort(candidates.begin(), candidates.end());
        vector<int>curr;
        // initially indx is 0, and total is 0
        generateSubsets(candidates, target, 0, curr, 0, res);

        return vector<vector<int>>(res.begin(), res.end());
    }
};
