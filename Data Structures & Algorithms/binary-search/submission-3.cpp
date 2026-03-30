class Solution {
public:
    int search(vector<int>& nums, int target) {
        // using lower bound
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] >= target){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return (left < nums.size() && nums[left ] == target) ? left : -1;
    }
};
