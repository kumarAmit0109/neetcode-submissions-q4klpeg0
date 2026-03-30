class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;
        unordered_set<int>store(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            int streak = 1;
            while(store.find(curr+1)!=store.end()){
                streak++;
                curr++;
            }
            maxLen = max(maxLen, streak);
        }
        return maxLen;
    }
};
