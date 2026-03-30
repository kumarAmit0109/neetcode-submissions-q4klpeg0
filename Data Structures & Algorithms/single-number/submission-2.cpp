class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // after sorting the num array duplicates will stand side by side
        // so we can simply eliminate the option now
        sort(begin(nums), end(nums));
        int i = 0;
        while (i < nums.size() - 1) {
            if (nums[i] == nums[i + 1]) {
                i += 2;
            } else {
                return nums[i];
            }
        }
        return nums[i];
    }
};