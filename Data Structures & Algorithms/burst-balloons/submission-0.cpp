class Solution {
public:
    int dfs(vector<int>& nums){
        // size equals to 2, indicates only boundary balloons left, 
        // so nothing to burst, simply return 0
        if(nums.size() == 2){
            return 0;
        }

        int maxCoins = 0;
        // try bursting every balloon one by one (excluding boundaries)
        for(int i = 1; i < nums.size()-1; i++){
            // burst balloon i and get coins from its neighbors
            int coins = nums[i-1] * nums[i] * nums[i+1];

            // create a new array with balloon i removed
            vector<int> newNums = nums;
            newNums.erase(newNums.begin()+i);
            coins += dfs(newNums);

            maxCoins = max(maxCoins, coins);
        }
        return maxCoins;
    }
    int maxCoins(vector<int>& nums) {
        // add 1 to begining and the end to avoids out-of-bounds when 
        // bursting first or last balloon as now they always have a 1 as neighbor.
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
         // try all possible burst orders and return the maximum coins
        int res = dfs(nums);
        return res;
    }
};
