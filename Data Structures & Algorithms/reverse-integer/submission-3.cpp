class Solution {
public:
    int reverse(int x) {
        // convert to long long first to avoid overflow
        long long temp = llabs((long long)x);
        // convert to string
        string str = to_string(temp);
        // because of same name here call reverse from std namespace
        std :: reverse(str.begin(), str.end());

        long long res = stoll(str);
        // Restore sign if original number was negative
        if(x < 0){
            res *= -1;
        }
        // Check for 32-bit integer overflow
        if(res < INT_MIN || res > INT_MAX){
            return 0;
        }
        return (int)res;
    }
};
