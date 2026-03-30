class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>mp;
        
        for(int i = 0; i < numbers.size(); i++){
            int remaining = target - numbers[i];
            if(mp.find(remaining) != mp.end()){
                return {mp[remaining] + 1, i+1};
            }
            mp[numbers[i]] = i;
        }
        return {};
    }
};
