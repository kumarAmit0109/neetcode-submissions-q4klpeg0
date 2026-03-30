/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // sort the intervals by the increasing order by their start point
        sort(intervals.begin(), intervals.end(), [](auto& x, auto& y){
            return x.start < y.start;
        });

        // after sorting for intervals to overlap the start of second interval
        // must be smaller than the end of first interval
        for(int i = 1; i < intervals.size(); i++){ 
            if(intervals[i - 1].end > intervals[i].start){
                return false;
            }
        }
        return true;
    }
};
