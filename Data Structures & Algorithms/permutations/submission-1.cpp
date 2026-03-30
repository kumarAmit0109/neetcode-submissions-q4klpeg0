class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // empty array means empty permutation
        if(nums.empty()){
            return {{}};
        }
        // create a copy of array fromnxt element to end nd 
        // use this temp to make a call for permutation of temp array
        vector<int> temp = vector<int>(nums.begin()+1, nums.end());
        vector<vector<int>> tempAns = permute(temp);

        // now insert the first element at all postion of the each of 
        // calculated indivisual permutations of temp array
        vector<vector<int>>res;
        for(const auto& p : tempAns){
            for(int i = 0; i <= p.size(); i++){
                vector<int>p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                res.push_back(p_copy);
            }
        } 
        return res;
    }
};
