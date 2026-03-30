class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);
        
        int m = nums1.size();
        int n = nums2.size();
        
        int low = 0, high = m;
            
        // Binary search on nums1
        while (low <= high) {

            // Px = partition index in nums1
            int Px = low + (high - low) / 2;

            // Py = partition index in nums2
            // Total elements on left side should be (m+n+1)/2
            int Py = (m + n + 1) / 2 - Px;

            // Left and right boundary values around partition in nums1
            int x1 = (Px == 0) ? INT_MIN : nums1[Px - 1];  // left of partition
            int x3 = (Px == m) ? INT_MAX : nums1[Px];      // right of partition

            // Left and right boundary values around partition in nums2
            int x2 = (Py == 0) ? INT_MIN : nums2[Py - 1];
            int x4 = (Py == n) ? INT_MAX : nums2[Py];

            // Check if we found the correct partition
            // All left-side elements <= all right-side elements
            if (x1 <= x4 && x2 <= x3) {

                // Even total length → average of two middle values
                if ((m + n) % 2 == 0)
                    return (max(x1, x2) + min(x3, x4)) / 2.0;

                // Odd total length → max of left side
                return max(x1, x2);

            }
            // Too many elements taken from nums1 → move left
            else if (x1 > x4) {
                high = Px - 1;
            }
            // Too few elements taken from nums1 → move right
            else {
                low = Px + 1;
            }
        }
        // Should never reach here if input is valid
        return -1;
    }
};
