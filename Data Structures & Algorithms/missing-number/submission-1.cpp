class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // insert all elements of array in set nd then iterate from 0 to n 
        // and check whether entry is created in set or not
        unordered_set<int> numSet(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i <= n; i++){
            if(numSet.find(i) == numSet.end()){
                return i;
            }
        }
        return -1;
    }
};
