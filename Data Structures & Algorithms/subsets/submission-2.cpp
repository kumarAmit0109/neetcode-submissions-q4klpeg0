class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // total no. of subset is power(2,n)
        int total = 1 << n;
        vector<vector<int>>res;

        for(int i = 0; i < total; i++){
            // for every bitmask we includes the elements of the nums array 
            // based on whether the bit in bitmask is set or not 
            vector<int>subset;
            for(int j = 0; j < n; j++){
                if(i & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        
        return res;
    }
};
