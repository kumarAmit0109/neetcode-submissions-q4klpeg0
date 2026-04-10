class Solution {
public:
    int solve(int n){
        if(n == 0){
            return 1;
        }

        if(n < 0){
            return 0;
        }

        // no. of ways to reach the top will be sum of the no. of ways to 
        // reach the n-1th step + no. of ways to reach the n-2th step
        return solve(n-1) + solve(n-2);

    }
    int climbStairs(int n) {
        int ans = solve(n);
        return ans;
    }
};
