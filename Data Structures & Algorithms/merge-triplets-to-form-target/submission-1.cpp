class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // when we merge triplets we take the max value at each index so values
        // only increase never decrese, therefore, any triplet that has a value 
        // greater than the target at any index cannot be used to form the target
        // so, instead of collecting indices in set, we can think like
        // to reach target[0] we need atleast one triplet where the first value is target
        // and other two doesn't exceed the target, same for target[1] and target[2]
        
        bool t0 = false; // set true only if t[0] == target[0] ,t[1] <= target[1], t[2] <= target[2]
        bool t1= false;  // set true only if t[0] <= target[0] ,t[1] == target[1], t[2] <= target[2]
        bool t2 = false; // set true only if t[0] <= target[0] ,t[1] <= target[1], t[2] == target[2]
        

        for(const auto& t : triplets){
            
            if((t[0] == target[0]) && (t[1] <= target[1]) && (t[2] <= target[2])){
                t0 = true;
            }
            if((t[0] <= target[0]) && (t[1] == target[1]) && (t[2] <= target[2])){
                t1 = true;
            }
            if((t[0] <= target[0]) && (t[1] <= target[1]) && (t[2] == target[2])){
                t2 = true;
            }
        }

        return t0 && t1 && t2;
    }
};
