class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // here we swap whole 32 bits in half half part at each step like 
        // first swap left 16 bits with right 16 bits
        // then now we have 2 16 bits halves so inside each half we swap in pairs of 8 now
        // and then in pairs of 4 , 2 and finally 1 
        // Step 1 → swap 16-bit halves
        // Step 2 → swap 8-bit blocks
        // Step 3 → swap 4-bit blocks
        // Step 4 → swap 2-bit blocks
        // Step 5 → swap 1-bit blocks
        // Final → fully reversed bits
        uint32_t ret = n;
        ret = (ret >> 16) | (ret << 16);
        ret = ((ret & 0xff00ff00) >> 8) | ((ret & 0x00ff00ff) << 8);
        ret = ((ret & 0xf0f0f0f0) >> 4) | ((ret & 0x0f0f0f0f) << 4);
        ret = ((ret & 0xcccccccc) >> 2) | ((ret & 0x33333333) << 2);
        ret = ((ret & 0xaaaaaaaa) >> 1) | ((ret & 0x55555555) << 1);
        return ret;
    }
};
