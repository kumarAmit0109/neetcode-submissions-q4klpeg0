class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // use hashset to keep track of whether the num exist earlier or not
        unordered_set<int>seen;
        for(int num : nums){
            // if element found in set simply erase it else insert
            if(seen.count(num)){
               seen.erase(num);
            }else{
                seen.insert(num);
            }
        }
        // in the end only one element is left in set,
        // that's our answer
        return *seen.begin(); 
    }
};
