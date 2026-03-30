class Solution {
public:
    long long calculateHours(vector<int>& piles, int k) {
        long long time = 0; // Change to long long to avoid overflow
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] + k - 1) / k;  // integer ceiling
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin(), piles.end());

        for (int rate = 1; rate <= maxi; rate++) {
            long long timeTaken = calculateHours(piles, rate);
            if (timeTaken <= h) {
                return rate;
            }
        }
        return maxi;
    }
};
