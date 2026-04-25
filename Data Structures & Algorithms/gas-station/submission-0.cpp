class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        // try with every index as the start point check whether its
        // possible to travell all points or not if yes simply return
        for(int i = 0; i < n; i++){
            // initialize the tank with the gas - cost at that indx
            int tank = gas[i] - cost[i];
            // if it becomes -ve simply ignore nd continue
            if(tank < 0){
                continue;
            }
            // in rest case try to make round trip
            int j = (i + 1) % n;
            while(j != i){
                tank += gas[j] - cost[j];
                if(tank < 0){
                    break;
                }
                j = (j + 1) % n;
            }
            // we reach the end
            if(j == i){
                return i;
            }
        }
        return -1;
    }
};
