class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        // use Brian Kernighan’s Idea
        // Instead of checking every bit, we remove one 1 at a time.
        // Key trick: n = n & (n - 1) This operation removes the rightmost 1 bit.
        for (int i = 1; i <= n; i++) {
            int num = i;
            while (num != 0) {
                res[i]++;
                num &= (num - 1);
            }
        }
        return res;
    }
};