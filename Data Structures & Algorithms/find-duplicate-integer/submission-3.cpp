class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int num : nums){
            int indx = abs(num) - 1;
            if(nums[indx] < 0){
                return abs(num);
            }
            nums[indx] = -nums[indx];
        }
        return -1;
    }
};
