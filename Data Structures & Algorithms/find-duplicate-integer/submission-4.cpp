class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 1, high = n - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            int lessOrEqual = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] <= mid){
                    lessOrEqual++;
                }
            }
            if(lessOrEqual <= mid){
                low = mid + 1;
            }else{
                high = mid;
            }
        }
        return low;
    }
};
