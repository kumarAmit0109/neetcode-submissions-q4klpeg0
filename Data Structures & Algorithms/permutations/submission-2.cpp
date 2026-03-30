class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // Start with one empty permutation
        vector<vector<int>> perms = {{}};

        // Process each number in nums one by one
        for(int num : nums){
            // This will store new permutations formed after adding current num
            vector<vector<int>> new_perms;
            // Go through all existing permutations
            for(const auto &p : perms){
                // Insert current number at every possible position
                for(int i = 0; i <= p.size(); i++){
                    // Make a copy of current permutation
                    vector<int> p_copy = p;
                    // Insert num at position i
                    p_copy.insert(p_copy.begin() + i, num);
                    // Add this new permutation to new_perms
                    new_perms.push_back(p_copy);
                }
            }
            // Update perms with newly formed permutations
            perms = new_perms;
        }
        // Return all permutations
        return perms;
    }
};