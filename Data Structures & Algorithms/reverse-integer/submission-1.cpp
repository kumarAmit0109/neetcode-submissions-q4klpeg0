class Solution {
public:
    long solve(int n, long rev){
        // Base case: if no digits left, return the reversed number
        if(n == 0){
            return rev;
        }

        // Extract last digit
        int digit = n % 10;

        // Add digit to reversed number
        rev = rev * 10 + digit;

        // Recursive call for remaining digits
        return solve(n / 10, rev);
    }

    int reverse(int x) {
        // Reverse the absolute value of x
        long res = solve(abs(x), 0);

        // Restore sign if original number was negative
        if(x < 0){
            res = -1 * res;
        }

        // Check for 32-bit integer overflow
        if(res < INT_MIN || res > INT_MAX){
            return 0;
        }

        return (int)res;
    }
};