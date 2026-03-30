class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>maxHeap;
        vector<int>ans;

        for(int i = 0; i < nums.size(); i++){
            maxHeap.push({nums[i], i});
            if(i >= k -1){
                while(maxHeap.top().second <= i - k){
                    maxHeap.pop();
                }
                ans.push_back(maxHeap.top().first);
            }
        }
        return ans;
    }
};
