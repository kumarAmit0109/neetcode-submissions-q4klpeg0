class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n = nums.size();   
        int res = 0;           

        // Check every bit position (0 to 31)
        for(int b = 0; b < 32; b++){

            int x = 0;  // Count of set bits at position 'b' in the given array
            int y = 0;  // Count of set bits at position 'b' in numbers from 1 to n-1

            int mask = 1 << b; // Mask to check the b-th bit

            // Count how many numbers in nums have the b-th bit set
            for(int num : nums){
                if(num & mask){
                    x++;
                }
            }

            // Count how many numbers from 1 to n-1 SHOULD have the b-th bit set
            for(int num = 1; num < n; num++){
                if(num & mask){
                    y++;
                }
            }

            // If actual count is more than expected count,
            // then this bit must belong to the duplicate number
            if(x > y){
                res |= mask;   // Set this bit in result
            }
        }

        // After checking all bits, res contains the duplicate number
        return res;
    }
};
