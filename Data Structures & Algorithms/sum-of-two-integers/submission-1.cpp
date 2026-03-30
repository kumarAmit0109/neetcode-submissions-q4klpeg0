class Solution {
public:
    int getSum(int a, int b) {
        int ans = 0;      
        int carry = 0;    
        for (int i = 0; i < 32; i++) {
            // extract ith bit of a and b
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            // add bits and carry
            int sum = bitA + bitB + carry;
            // result bit goes into ans
            int resultBit = sum % 2;
            ans |= (resultBit << i);
            // update carry
            carry = sum / 2;
        }

        return ans;
    }
};
