class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // If there are no intervals, simply return the new interval
        if (intervals.empty()) {
            return {newInterval};
        }
        int n = intervals.size();
        // We want to insert newInterval at the correct position
        // based on its start value
        int target = newInterval[0];
        int left = 0, right = n - 1;
        //  Binary Search to find the correct index where newInterval should be inserted
        while (left <= right) {
            int mid = (left + right) / 2;
            // If current interval start is smaller than target,
            // move to the right half
            if (intervals[mid][0] < target) {
                left = mid + 1;
            } 
            else {
                // Otherwise move to the left half
                right = mid - 1;
            }
        }

        // Insert newInterval at the correct sorted position
        intervals.insert(intervals.begin() + left, newInterval);
        // This will store the final merged intervals
        vector<vector<int>> res;
        // Traverse all intervals and merge overlapping ones
        for (const auto& interval : intervals) {
            // If result is empty OR current interval does not overlap
            // with the last interval in result
            if (res.empty() || res.back()[1] < interval[0]) {
                // Simply add it to result
                res.push_back(interval);
            } 
            else {
                // If intervals overlap, merge them by updating the end
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        // Return the merged interval list
        return res;
    }
};