class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // with the help of simple math we can easily find
        // missing number = sum(0 - nums.size()) - sum(elements in array);
        int sumOfZeroToNumsSize = 0; 
        int sumOfNumsArray = 0; 
        for(int i = 0; i < nums.size(); i++){
            sumOfZeroToNumsSize += i;
            sumOfNumsArray += nums[i];
        }
        // fixing the sum as its include ( 0 to nums.size())
        sumOfZeroToNumsSize += nums.size();
        return sumOfZeroToNumsSize  - sumOfNumsArray;
    }
};
