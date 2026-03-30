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
        // use sweep line algorithm 
        // use map to record the strt nd end of meeting in interval, for each meeting:
        // increment mp[start](meeting starts) nd decrement mp[end](meeting ends)
        map<int, int>mp;
        for(auto& interval : intervals){
            mp[interval.start]++;
            mp[interval.end]--;
        }

        int prev = 0; // current number of ongoing meetings
        int res = 0;  // maximum rooms needed

        // Sweep through all time points in sorted order
        for (auto& [time, change] : mp) {
            // Update current active meetings
            prev += change;
            // Track maximum number of simultaneous meetings
            res = max(res, prev);
        }
        return res;
    }
};
