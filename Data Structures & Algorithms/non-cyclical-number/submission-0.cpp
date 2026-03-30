class Solution {
public:
    int sumOfSquares(int n){
        int ans = 0;
        while(n != 0){
            int digit = n % 10;
            ans += digit * digit;
            n /= 10;
        }
        return ans;
    }

    bool isHappy(int n) {
        unordered_set<int> visited;

        while(true){
            if(n == 1){
                return true;
            }

            if(visited.find(n) != visited.end()){
                return false;
            }

            visited.insert(n);
            n = sumOfSquares(n);
        }
    }
};