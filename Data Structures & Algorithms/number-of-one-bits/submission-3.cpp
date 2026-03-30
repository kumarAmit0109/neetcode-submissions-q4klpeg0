class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        // Loop runs until n becomes 0
        // Each iteration removes one '1' bit from n
        while(n){
            // Trick: n & (n - 1) removes the rightmost set bit (1)
            // Example:
            // n = 1011
            // n-1 = 1010
            // AND = 1010  → rightmost 1 removed
            n = n & (n - 1);
            // Since one '1' was removed, increase the counter
            cnt++;
        }
        return cnt;
    }
};
