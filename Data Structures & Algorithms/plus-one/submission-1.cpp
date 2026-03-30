class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());

        int i = 0;

        while(i < digits.size()){
            if(digits[i] == 9){
                digits[i] = 0;
            }else{
                digits[i] += 1;
                reverse(digits.begin(), digits.end());
                return digits;
            }
            i++;
        }

        // if all digits were 9
        digits.push_back(1);

        reverse(digits.begin(), digits.end());
        return digits;
    }
};