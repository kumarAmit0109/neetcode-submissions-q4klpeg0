class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Map to store boundary changes
        // key = position on number line
        // value = +1 if interval starts, -1 if interval ends
        map<int,int> mp;
        // Convert intervals into sweep line events
        for(auto interval : intervals){
            mp[interval[0]]++; // interval starts
            mp[interval[1]]--; // interval ends
        }

        vector<vector<int>> res;   // final merged intervals
        vector<int> interval;      // current interval being built
        int have = 0;              // number of active intervals
        // Sweep from left to right across all boundary points
        for(auto [pos, count] : mp){
            // If interval is empty, this position could be start of new merged interval
            if(interval.empty()){
                interval.push_back(pos);
            }
            // Update number of active intervals
            have += count;
            // If active intervals become zero
            // it means all overlapping intervals ended here
            if(have == 0){
                interval.push_back(pos); // mark end
                res.push_back(interval); // store merged interval
                interval.clear();        // reset for next interval
            }
        }
        return res;
    }
};