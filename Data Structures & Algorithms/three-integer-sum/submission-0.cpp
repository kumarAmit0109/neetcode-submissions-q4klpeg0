class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> seen;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){  
                    if(nums[i] + nums[j] + nums[k] == 0){
                        seen.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(seen.begin(), seen.end());
    }
};
