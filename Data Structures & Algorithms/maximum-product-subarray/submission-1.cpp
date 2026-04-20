class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];  // stores the best product found so far

        int prefix = 0;  // running product from LEFT side (0 means "not started / just reset")
        int suffix = 0;  // running product from RIGHT side (0 means "not started / just reset")

        for (int i = 0; i < n; i++) {

            // PREFIX (left to right)
            // if prefix is 0 (fresh start), just take current number alone
            // otherwise keep multiplying with previous product
            prefix = nums[i] * (prefix == 0 ? 1 : prefix);

            // SUFFIX (right to left)
            // n-1-i walks from the end of array towards the start
            // same reset logic: if suffix is 0, start fresh from current number
            suffix = nums[n - 1 - i] * (suffix == 0 ? 1 : suffix);

            // update result with the best of: previous best (res), current
            // left-side product (prefix) and current right-side product (suffix)
            res = max(res, max(prefix, suffix));
        }

        return res; 
    }
};