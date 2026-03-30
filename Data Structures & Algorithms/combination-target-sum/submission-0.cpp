class Solution {
public:
    void backtrack(vector<int>& nums, int target, vector<int>& temp, vector<vector<int>>& res, int indx){
        // if target is 0, means we make the target so simply store nd return
        if(target == 0){
            res.push_back(temp);
            return;
        }
        // if target is less than 0 , or we exceded the nums array so 
        // its not possible to make target in such cases so simply return 
        if(target < 0 || indx >= nums.size()){
            return;
        }
        // make call by including the current element
        temp.push_back(nums[indx]);
        backtrack(nums, target - nums[indx], temp, res, indx);
        // make call by excluding the current elememt
        temp.pop_back();
        backtrack(nums, target, temp, res, indx+1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int>temp;
        vector<vector<int>>res;
        // strt backtracking with the index 0
        // we simply including the curr element nd then strt fxn calling with same indx as we can 
        // duplication is allowed , second we simply excude the indx nd call 
        // this ways we simply avoid the duplicate vector in our answer
        backtrack(nums, target, temp, res, 0);
        return res;
    }
};
