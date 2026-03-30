class Solution {
public:
    bool canJump(vector<int>& nums) {
        // Step 1: Set goal as the last index
        // We want to check if we can reach this position
        int goal = nums.size() - 1;
        // Step 2: Traverse the array backwards
        // Start from second last index and move to index 0
        for(int i = nums.size() - 2; i >= 0; i--){
            // Check if from index i we can reach the current goal
            // i + nums[i] gives the farthest we can jump from i
            if(i + nums[i] >= goal){
                // If yes, update goal to i
                // Now we just need to check if we can reach i
                goal = i;
            }
        }
        // Step 3: Final check
        // If goal becomes 0, it means we can reach the end from start
        return goal == 0;
    }
};