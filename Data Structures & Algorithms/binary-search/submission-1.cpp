class Solution {
public:
    int iterative_binary(vector<int>& nums, int start, int end, int target){

        while(start <= end){
            int mid = start + (end - start)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid -1;
            }else{
                start = mid + 1;   
            }
        }
        return -1;      
    }
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size()-1;
        return iterative_binary(nums, start, end, target);
    }
};
