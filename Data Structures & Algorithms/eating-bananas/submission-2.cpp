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

        int strt = 1, end = maxi;
        while(strt <= end){
            int mid = strt + (end - strt)/2;
            int time = calculateHours(piles, mid);
            if(time <= h){
                end = mid - 1;
            }else{
                strt = mid + 1;
            }
        }
        return strt;
    }
};
