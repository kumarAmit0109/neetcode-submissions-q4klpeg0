class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixProd(n);
        prefixProd[0] = 1;
        for(int i = 1; i < n; i++){
            prefixProd[i] = prefixProd[i-1] * nums[i-1];
        }
        
        vector<int>ans(n);
        int suffixProd = 1;
        for(int i = n-1; i >= 0; i--){
            ans[i] = prefixProd[i] * suffixProd;
            suffixProd *= nums[i];
        }
        return ans;
    }
};
