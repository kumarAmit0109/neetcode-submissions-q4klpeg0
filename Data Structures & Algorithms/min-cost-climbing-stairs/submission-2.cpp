class Solution {
public:
    int solve(int n, vector<int>&cost){
        // if we reach 0th floor then simply return cost of 0th floor
        if(n == 0){
            return cost[0];
        }
        // if we reach 1st floor then simply return cost of 0th floor
        if(n == 1){
            return cost[1];
        }
        // calculate min cost to reach n-1 th floor
        int res1 = solve(n-1, cost);
        // calculate min cost to reach n-2 th floor
        int res2 = solve(n-2, cost);
        
        // overall cost to reach nth floor is min of costs to reach n-1th
        // n-2th floor + cost of nth floor
        return min(res1, res2) + cost[n];

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        // Top is beyond last index → choose min of last two
        int ans =  min(solve(n-1, cost), solve(n-2, cost));
        // int ans = solve(n, cost);
        return ans;
    }
};
