class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1, 0);
        // use builtin method
        for (int i = 0; i <= n; i++) {
            res[i] = __builtin_popcount(i);
        }
        return res;
    }
};