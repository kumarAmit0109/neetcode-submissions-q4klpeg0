class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for(int i = 0; i < 32; i++){
            // create a mask with ith bit set and then take bitwise-And of
            // mask and n in order to check whether ith bit of n is set or not
            int mask = 1 << i;
            if(mask & n){
                res++;
            }
        }

        return res;
    }
};
