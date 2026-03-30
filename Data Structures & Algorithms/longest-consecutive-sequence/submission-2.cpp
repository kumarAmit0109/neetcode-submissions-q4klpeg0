class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        sort(nums.begin(), nums.end());

        int ans = 1;
        int streak = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                continue; // skip duplicate
            }
            else if (nums[i] == nums[i - 1] + 1) {
                streak++;
            }
            else {
                streak = 1; // reset streak
            }
            ans = max(ans, streak);
        }
        return ans;
    }
};
