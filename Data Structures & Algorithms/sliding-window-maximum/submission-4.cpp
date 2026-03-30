class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;

        for(int i = 0; i < nums.size(); i++){
            // 1. Remove indices outside window
            if( !dq.empty() && i - k ==  dq.front()){
                dq.pop_front();
            }
            // 2. Remove smaller elements
            while(!dq.empty() && nums[dq.back()] < nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            // 3. Store answe
            if(i + 1 >= k){
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
