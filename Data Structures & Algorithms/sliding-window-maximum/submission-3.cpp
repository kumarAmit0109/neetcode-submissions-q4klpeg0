class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ans;
        deque<int>dque;
        int left = 0, right = 0;
        
        while(right < n){
            // 1. Remove indices outside window
            if (!dque.empty() && dque.front() < left) {
                dque.pop_front();
            }
            // 2. Remove smaller elements
            while(!dque.empty() && nums[dque.back()] < nums[right]){
                dque.pop_back();
            }
            dque.push_back(right);

            // 3. If window size == k, record answer
            if (right - left + 1 == k) {
                ans.push_back(nums[dque.front()]);
                left++;   // slide window
            }

            right++;
        }
        return ans;
    }
};
