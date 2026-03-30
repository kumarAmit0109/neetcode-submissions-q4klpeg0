class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        for (int n : nums) {
            freqMap[n]++;
        }

        vector<vector<int>> freq(nums.size() + 1);
        for (auto &p : freqMap) {
            freq[p.second].push_back(p.first);
        }

        vector<int> ans;
        for (int i = nums.size(); i >= 1 && ans.size() < k; i--) {
            for (int n : freq[i]) {
                ans.push_back(n);
                if (ans.size() == k) {
                    break;
                }
            }
        }
        return ans;
    }
};
