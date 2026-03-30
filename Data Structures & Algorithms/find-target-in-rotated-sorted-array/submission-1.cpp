class Solution {
public:
    int getPivot(vector<int>nums){
        int strt = 0, end = nums.size() - 1;
        while(strt < end){
            int mid = strt + (end - strt)/2;
            if(nums[mid] >= nums[0]){
                strt = mid + 1;
            }else{
                end = mid;
            }
        }
        return strt;
    }

    int binarySearch(vector<int>nums, int target, int strt, int end){
        while(strt <= end){
            int mid = strt + (end - strt)/2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] < target){
                strt = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int pivot = getPivot(nums);
        int strt = 0, end = nums.size() - 1;
        if (nums[pivot] == target) return pivot;
        if (pivot == 0 || nums[0] > nums[end]) {
            if(target >= nums[0]){
                return binarySearch(nums, target, 0, pivot - 1);
            }else{
                return binarySearch(nums, target, pivot, end);
            }
        }
    }
};
