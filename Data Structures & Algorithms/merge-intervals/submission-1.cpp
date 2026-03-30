class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        // after sorting we can easily compare the end of first interval with 
        // the start of second interval if its greater than,then we have to merge
        // them by keeping strt of new interval same as first and end should be max 
        // of end of first and end of second interval
        vector<vector<int>>output;
        output.push_back(intervals[0]);
        
        for(auto& interval : intervals){
            int strt = interval[0];
            int end = interval[1];

            vector<int>lastInterval = output.back();
            int lastEnd = lastInterval[1];

            if(strt <= lastEnd){
                // merge the interval by adjusting the end of previous Interval
                output.back()[1] = max(lastEnd, end);
            }else{
                // insert the interval into output without merging
                output.push_back({strt, end});
            }
        }
        return output;
    }   
};
