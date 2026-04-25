class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int res = 0;
        int balance = 0;
        // the idea is simple while travelling if we find that strting from 
        // 0th index and after reaching 4th index total become -ve means we cann't
        // complete the circle even we start from 1,2,3,or 4th so its better don't
        // waste iteration simply strt from 5th index
        for(int i = 0; i < gas.size(); i++){
            total += (gas[i] - cost[i]);
            // if total becomes -ve means we cann't reach the end so start
            // from nxt postion nd reset the total 
            if(total < 0){
                balance += total; // accumulate the negative chunk
                total = 0;
                res = i + 1;
            }
        }    
        // balance + total = overall sum of all (gas[i] - cost[i])
        // if overall sum < 0 → impossible to complete circuit
        if(balance + total < 0){  
            return -1;
        }
        return res;
    }
};
