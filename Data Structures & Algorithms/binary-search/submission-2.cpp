class Solution {
public:
    int search(vector<int>& nums, int target) {
        // using upper bound
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] > target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return (left > 0 && nums[left -1] == target) ? left -1 : -1;
    }
};
