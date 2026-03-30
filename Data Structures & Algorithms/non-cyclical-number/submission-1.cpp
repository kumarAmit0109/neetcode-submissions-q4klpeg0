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
        // think like a linkedlist nd use floyd cycle detection algo for
        // detecting whether slow or fast meet eventually or if its end at
        // including 1 in the linkedlist at any step

        int slow = n;
        int fast = sumOfSquares(n);

        while(slow != fast){
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
            slow = sumOfSquares(slow);
        }
        

        if(fast == 1){
            return true;
        }else{
            return false;
        }
        
    }
};