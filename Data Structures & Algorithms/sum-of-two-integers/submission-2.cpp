class Solution {
public:
    int getSum(int a, int b) {
        int ans = a;   // start with a as initial value
        while (b != 0) {
            int carry = (ans & b) << 1; // calculate carry
            ans = ans ^ b;              // add without carry
            b = carry;                  // carry will be added in next iteration
        }
        return ans;
    }
};
