class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> mp;
        sort(nums.begin(), nums.end());

        for (int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]--;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[j]]--;
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int req = -(nums[i] + nums[j]);

                if (mp[req] > 0 && req >= nums[j]) {
                    ans.push_back({nums[i], nums[j], req});
                }
            }

            // restore counts
            for (int j = i + 1; j < nums.size(); j++) {
                mp[nums[j]]++;
            }
            mp[nums[i]]++;
        }

        return ans;
    }
};
