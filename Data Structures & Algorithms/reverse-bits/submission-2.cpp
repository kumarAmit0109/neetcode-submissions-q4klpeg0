class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            // extract the ith bit
            int bit = (n >> i) & 1;
            // place it at the reversed positon
            res |= (bit << (31 - i));
        }
        return res;
    }
};
