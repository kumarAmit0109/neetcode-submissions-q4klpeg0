class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // check whether each no. exist in rest vector with the help of 2 loops
        for(int i = 0; i < nums.size(); i++){
            // initially mark that the no. is unique
            bool flag = true;
            for(int j = 0; j < nums.size(); j++){
                if(i != j && nums[i] == nums[j]){
                    flag = false;
                    break;
                }
            }
            
            // if flag is still true means nums[i] is unique simply return
            if(flag){
                return nums[i];
            }
        }
        return -1;
    }
};
