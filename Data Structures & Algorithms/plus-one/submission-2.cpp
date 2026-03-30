class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // it follow basic principal of how addition works
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // means the digits[i] is 9, so make it 0
            digits[i] = 0;
        }
        
        // if not returned yet means we there is all the 9's in array, 
        // so simply return 1 followed by zero(whose count is equal to digits.size)
        vector<int> result(n + 1);
        result[0] = 1;
        return result;
    }
};