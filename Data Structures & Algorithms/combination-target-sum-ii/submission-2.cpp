class Solution {
public:
    vector<vector<int>> res; // stores all valid combinations
    unordered_map<int, int> count;// stores frequency of each number
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;            
        vector<int> arr; // stores unique numbers only
        // build frequency map and unique array
        for(int num : candidates){
            // if number seen first time, add to unique array
            if(!count[num]){
                arr.push_back(num);
            }
            count[num]++;    
        }
        // start backtracking from index 0
        backtrack(arr, target, curr, 0);
        return res;
    }

    void backtrack(vector<int>& nums, int target, vector<int>& curr, int i){
        // if target becomes 0, valid combination found
        if(target == 0){
            res.push_back(curr);
            return;
        }
        // stop if target becomes negative OR index out of bounds
        if(target < 0 || i >= nums.size()){
            return;
        }

        // include current element 
        if(count[nums[i]]){ // only include if frequency available
            curr.push_back(nums[i]);
            count[nums[i]]--;  
            // stay at same index because same number can be used again (if freq > 0)
            backtrack(nums, target - nums[i], curr, i);

            // backtrack
            count[nums[i]]++; 
            curr.pop_back(); 
        }

        // exclude current element 
        // move to next index
        backtrack(nums, target, curr, i+1);

    }
};