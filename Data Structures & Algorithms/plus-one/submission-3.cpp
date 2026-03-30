class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // If the vector becomes empty, it means all digits were 9.
        // Example: [9,9,9] → after removing all 9s → []
        // So the result should start with 1.
        if(digits.empty()){
            return {1};
        }

        // If the last digit is less than 9,
        // we can simply add 1 and return the result.
        // Example: [1,2,3] → [1,2,4]
        if(digits.back() < 9){
            digits.back() += 1;
            return digits;
        }else{
            // If the last digit is 9:
            // 9 + 1 = 10 → write 0 and carry 1 to the left.
            // So we remove the last digit first.
            digits.pop_back();

            // Recursively call plusOne on the remaining digits
            // to handle the carry.
            vector<int> result = plusOne(digits);

            // Since 9 + 1 becomes 0 (after carrying),
            // we add 0 back to the end.
            result.push_back(0);

            // Return the updated result.
            return result;
        }
    }
};