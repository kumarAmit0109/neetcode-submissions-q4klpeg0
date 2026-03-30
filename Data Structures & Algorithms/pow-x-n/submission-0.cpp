class Solution {
public:
    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n == 0) {
            return 1;
        }

        double res = 1;
        for (int i = 0; i < abs(n); i++) {
            res *= x;
        }

        if(n >= 0){
            return res;
        }else{
            return 1/res;
        }
        
    }
};