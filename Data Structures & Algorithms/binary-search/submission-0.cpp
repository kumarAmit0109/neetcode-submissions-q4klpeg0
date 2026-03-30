class Solution {
public:
    int recursive_binary(vector<int>& nums, int start, int end, int target){
        if(start > end){
            return -1;
        }
        int mid = start + (end - start)/2;
        if(nums[mid] == target){
            return mid;
        }else if(nums[mid] > target){
            end = mid -1;
        }else{
            start = mid + 1;
            
        }
        return recursive_binary(nums, start, end, target );
    }
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        return recursive_binary(nums, start, end, target);
    }
};
