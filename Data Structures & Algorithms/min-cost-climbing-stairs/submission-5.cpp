class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // memory optimazation approach
        int n = cost.size();
        // Instead of using dp array, we store only last two values:
        // prev1 = minimum cost to reach step (i-2)
        // prev2 = minimum cost to reach step (i-1)
        int prev1 = cost[0]; // cost to reach step 0
        int prev2 = cost[1]; // cost to reach step 1
        
        for(int i = 2; i < n; i++){
            // To reach step i:
            // you can either come from (i-1) or (i-2)
            // so take minimum of both and add current cost
            int temp = min(prev1, prev2) + cost[i];
            prev1 = prev2;
            prev2 = temp;
        }

        // Final answer:
        // You can reach the top from either last step (n-1)
        // or second last step (n-2)
        return min(prev1, prev2);
    }
};