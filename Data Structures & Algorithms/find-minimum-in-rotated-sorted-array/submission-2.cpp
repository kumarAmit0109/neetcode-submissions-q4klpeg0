class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // minimum is in the right half
                left = mid + 1;
            } else {
                // minimum is in the left half (or at mid)
                right = mid;
            }
        }
        return nums[left];
    }
};
