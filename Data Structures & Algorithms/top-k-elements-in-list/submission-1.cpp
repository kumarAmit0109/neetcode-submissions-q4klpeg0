class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freqMap;
        for(int i = 0; i < nums.size(); i++){
            freqMap[nums[i]]++;
        }

        vector<pair<int,int>>arr;
        for(auto i : freqMap){
            arr.push_back(make_pair(i.second,i.first));
        }

        sort(arr.rbegin(), arr.rend());
        vector<int>ans;
        for(int count = 0; count < k; count++){
            ans.push_back(arr[count].second);
        }
       
        return ans;
    }
};
