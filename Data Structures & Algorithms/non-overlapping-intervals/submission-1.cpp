class Solution {
public:
    int solve(const vector<vector<int>>& intervals, int i, int prev){
        // indicates we have reached end, no more intervals to take
        if(i == intervals.size()){
            return 0;
        }
        // skip the current interval
        int res1 = solve(intervals, i+1, prev);

        // take the interval
        // if prev interval is not taken or its not overlaping then take it
        int res2 = 0;
        if(prev == -1 || intervals[prev][1] <= intervals[i][0]){
            res2 = 1 + solve(intervals, i+1, i);
        }
        return max(res1, res2);
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // instead of counting removals, we can count the maximun numbers
        // of intervals we can keep without overlap and then
        // minimum removals = total intervals - maximum kept
        sort(intervals.begin(), intervals.end());
        int maxKept = solve(intervals, 0, -1);
        int minimalRemoval = intervals.size() - maxKept;
        return minimalRemoval;
    }
};
