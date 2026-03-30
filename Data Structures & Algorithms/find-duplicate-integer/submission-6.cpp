class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        // move slow ptr one step and fast ptr two step
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }

        // now keep slow at strt , nd move slow nd fast both one step at time
        // untill they met
        slow = 0;
        while(true){
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast){
                return slow;
            }
        }
    }
};
