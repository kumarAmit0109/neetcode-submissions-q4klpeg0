class Solution {
public:
    double solve(double x, int n){
        if(n == 0){
            return 1;
        }

        double temp = solve(x, n/2);
        if(n % 2 == 0){
            return temp * temp;
        }else{
            return x * temp * temp;
        }
    }
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        double res = solve(x, abs(n));
        if(n >= 0){
            return res;
        }else{
            return 1/res;
        }
        
    }
};
