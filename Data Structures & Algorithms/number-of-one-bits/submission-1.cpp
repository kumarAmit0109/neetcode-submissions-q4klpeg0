class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        // simply and with 1 if it result-in non zero means least significant bit
        // is set, and after that right shift n and then repeat above cycle till
        // n becomes zero
        while(n != 0){
            if(n & 1){
                cnt++;
            }
            n = n>>1;
        }
        return cnt;
    }
};
