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
    int minMeetingRooms(vector<Interval>& intervals) {
        // separate all start and end times
        vector<int> start, end;
        for (const auto& i : intervals) {
            start.push_back(i.start); 
            end.push_back(i.end);     
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        // res = maximum rooms needed 
        // cnt = current number of active meetings
        // s = pointer for start times
        // e = pointer for end times
        int res = 0, cnt = 0, s = 0, e = 0;
        // traverse all start times
        while (s < intervals.size()) {
            // if next meeting starts before the earliest ending meeting
            if (start[s] < end[e]) {
                // need a new room
                cnt++;
                s++; // move to next start time
            } else {
                // one meeting has ended, so free a room
                cnt--;
                e++; // move to next end time
            }
            // update maximum rooms needed at any time
            res = max(res, cnt);
        }
        return res;
    }
};