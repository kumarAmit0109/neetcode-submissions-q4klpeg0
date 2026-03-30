class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> res;

        // Add all intervals that come completely BEFORE newInterval
        // Condition: interval.end < newInterval.start
        // These intervals do not overlap with newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            res.push_back(intervals[i]);  // simply add to result
            i++;
        }

        // Merge all overlapping intervals with newInterval
        // Overlap condition: intervals[i].start <= newInterval.end
        while (i < n && newInterval[1] >= intervals[i][0]) {
            // Update start of newInterval to the minimum start
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            // Update end of newInterval to the maximum end
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            // move to next interval to check further overlaps
            i++;
        }

        // After merging all overlaps, add the merged interval
        res.push_back(newInterval);
        // Add all remaining intervals that come AFTER newInterval
        // These intervals also do not overlap
        while (i < n) {
            res.push_back(intervals[i]);
            i++;
        }
        return res;
    }
};