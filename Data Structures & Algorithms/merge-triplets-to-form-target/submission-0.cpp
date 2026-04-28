class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // used to indicated which target indices are matched
        // if st = {0, 1, 2} at end then all 3 target values achievable
        unordered_set<int> st;

        // just like brute force iterate through each triplet, if any value there
        // is greater than the target triplets value so ignore as including it only
        // increases the value as we are taking the maximum
        // for remaining it is equal so store it, and in the end if the size of our set
        // is 3 means all triplets found
        for(auto triplet : triplets){
            // skip this triplet if any value exceeds target
            // because merging (taking max) would push that position above target
            if((triplet[0] > target[0]) || (triplet[1] > target[1]) || (triplet[2] > target[2])){
                continue;
            }

            // this triplet is safe to use then check if it contributes
            // any matching value at the same position as target
            for(int i = 0; i < triplet.size(); i++){
                if(triplet[i] == target[i]){
                    st.insert(i);  // position i is achievable via this triplet
                }
            }
        }

        // if all 3 positions {0, 1, 2} are in set then target is achievable
        return st.size() == 3;
    }
};