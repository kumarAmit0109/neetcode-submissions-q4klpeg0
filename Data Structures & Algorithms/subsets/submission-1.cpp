class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res = {{}};
        // For every number in the array, we take all the subsets we have so far and
        // create new subsets by adding the current number to each of them.
        for(int num : nums){
            int size = res.size();
            for(int i = 0; i < size; i++){
                // Copy the existing subset
                vector<int> subset = res[i];
                // Add current number to the copied subset
                subset.push_back(num);
                // Add the new subset into result
                res.push_back(subset);
            }
        }
        return res;
    }
};
