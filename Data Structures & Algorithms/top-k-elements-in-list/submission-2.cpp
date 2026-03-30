class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>freqMap;
        for(int i = 0; i < nums.size(); i++){
            freqMap[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minHeap;

        for(auto& i: freqMap){
            minHeap.push({i.second, i.first});
            if(minHeap.size() > k){
                minHeap.pop();
            }
        }
        vector<int>ans;
        for(int count = 0; count < k; count++){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
       
        return ans;
    }
};
