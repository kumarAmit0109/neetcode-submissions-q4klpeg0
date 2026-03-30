class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the nums array to avoid the duplicates
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back({});   // Start with empty subset

        int strtIndx = 0;     // Where to start adding new subsets
        int previousSize = 0;   // Size of result before processing current number

        for(int i = 0; i < nums.size(); i++){
            // if current number is duplicate only extend the subset created
            // in previous step else extend all the subset 
            if(i > 0 && nums[i] == nums[i-1]){
                strtIndx = previousSize;
            }else{
                strtIndx = 0;
            }

            // update the previous size
            previousSize = res.size();
            for(int j = strtIndx; j < previousSize; j++){
                vector<int>temp = res[j];
                temp.push_back(nums[i]);
                res.push_back(temp);
            }
        }

        return res;
    }
};
