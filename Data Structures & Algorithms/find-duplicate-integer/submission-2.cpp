class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int>seen(nums.size(), 0);
        for(int num : nums){
            if(seen[num - 1] != 0){
                return num;
            }
            seen[num -1] = 1;
        }
        return -1;
    }
};
