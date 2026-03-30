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
        int power = abs(n);
        
        while(power){
            // if power is odd then do res * x * x;
            // in case of even power do simply x * x
            if(power & 1){
                res *= x;
            }
            x *= x;
            // update power to half of current power
            power >>= 1;
        }

        if(n >= 0){
            return res;
        }else{
            return 1/res;
        }
        
    }
};