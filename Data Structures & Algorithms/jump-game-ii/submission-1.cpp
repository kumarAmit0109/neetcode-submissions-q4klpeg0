class Solution {
public:
    int dfs(vector<int>&nums, int i){
        // if we reach end simply return zero no more jumps needed
        if(i == nums.size() - 1){
            return 0;
        }

        // if we reach other position than end but not able to jump further
        // means we can move from there so return large value, indicating not able
        // to move from that positon
        if(nums[i] == 0){
            return 1000000;
        }

        int result = INT_MAX;
        int end = min((int)nums.size() - 1, i + nums[i]);
        // try all possible jumps from current position (j = i+1 to end)
        // for each jump destination, 1 + dfs(j) gives total jumps needed from here
        // keep track of the minimum among all choices
        for(int j = i+1; j <= end; j++){
            int minJumpsReqFromCurrPostion = 1 + dfs(nums, j);
            result = min(result, minJumpsReqFromCurrPostion);
        }
        return result;
    }
    int jump(vector<int>& nums) {
        // using recursion we try all possible jumps from the current index
        // and choose the one that leads to the end using the fewest total jumps
        // start with the 0 index
        int ans = dfs(nums, 0);
        return ans;
    }
};
