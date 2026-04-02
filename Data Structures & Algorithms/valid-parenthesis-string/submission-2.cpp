class Solution {
public:
    bool checkValidString(string s) {
        // leftMin = minimum possible open brackets
        // leftMax = maximum possible open brackets
        int leftMin = 0, leftMax = 0;
        for (char c : s) {
            if (c == '(') {
                // '(' increases both min and max
                leftMin++;
                leftMax++;
            } 
            else if (c == ')') {
                // ')' decreases both min and max
                leftMin--;
                leftMax--;
            } 
            else {
                // '*' can be:
                // treat as ')' → decrease min
                // treat as '(' → increase max
                leftMin--;
                leftMax++;
            }
            // if max goes negative → too many ')' → invalid
            if (leftMax < 0) {
                return false;
            }
            // min should never go below 0
            // because we can't have negative open brackets
            if (leftMin < 0) {
                leftMin = 0;
            }
        }
        // if min is 0 → we can balance all brackets
        return leftMin == 0;
    }
};