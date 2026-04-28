class Solution {
public:
    vector<int> partitionLabels(string s) {
        // keep a map to track the last occurance of every char
        unordered_map<char, int>lastIndex;
        for(int i = 0; i < s.size(); i++){
            lastIndex[s[i]] = i;
        }

        vector<int>res;
        int size = 0;
        int end = 0;
        
        for(int i = 0; i < s.size(); i++){
            size++;
            // extend boundary if current char appears further ahead
            // ensures all occurrences of this char are in current partition
            end = max(end, lastIndex[s[i]]);

            // i==end means all chars in current partition have their
            // last occurrence within this partition which means 
            // its safe to cut here
            if(i == end){
                res.push_back(size);
                // reset size for next partition
                size = 0;
            }
        }
        return res;
    }
};
