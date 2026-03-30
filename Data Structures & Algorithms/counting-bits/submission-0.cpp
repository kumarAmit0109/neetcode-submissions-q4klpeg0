class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        // simply count numbers of 1 in every number from 1 to n
        for (int num = 1; num <= n; num++) {
            for (int i = 0; i < 32; i++) {
                if (num & (1 << i)) {
                    res[num]++;
                }
            }
        }
        return res;
    }
};