class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k){
        int pivot = nums[right]; //Choose the last element as pivot
        int strt = left; // strt will store the correct position of pivot after rearranging

        // Rearrange elements,  Goal:
        // - all elements <= pivot → move to left side
        // - all elements > pivot → stay on right side
        for(int i = left; i < right; i++){
            if(nums[i] <= pivot){
                swap(nums[strt], nums[i]);
                strt++;
            }
        }
        // Put pivot in its correct sorted position
        // swap pivot with element at strt
        swap(nums[strt], nums[right]);

        // now pivot is at its correct sorted position,
        // simply check whether our ans lie at that position or its is in left
        // or right subpart nd proceed accordingly
        if(strt > k){
            return quickSelect(nums, left, strt-1, k);
        }else if(strt < k){
            return quickSelect(nums, strt+1, right, k);
        }else{
            return nums[strt];
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        // in quicksort we sort it in ascending order so, for kth largest elem
        // we will find the (nums.size() - k)th element
        int target = nums.size() - k;
        int res = quickSelect(nums, 0, nums.size() - 1, target);
        return res;
    }
};
