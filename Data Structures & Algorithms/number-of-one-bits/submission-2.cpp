class Solution {
public:
    int hammingWeight(uint32_t n) {
        // use built-in fxn
        return __builtin_popcount(n);
    }
};
