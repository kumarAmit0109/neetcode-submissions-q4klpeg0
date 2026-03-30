class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>elemToIndxMap;
        vector<int>ans(2);
        for(int i = 0; i < nums.size(); i++){
            elemToIndxMap[nums[i]] = i;
        }

        for(int i = 0; i < nums.size(); i++){
           int remaining = target - nums[i];
           if(elemToIndxMap.find(remaining) != elemToIndxMap.end() &&elemToIndxMap[remaining] != i){
            ans[0] = min(elemToIndxMap[remaining],i);
            ans[1] = max(elemToIndxMap[remaining],i);
           }
        }
        return ans;
    }
};
