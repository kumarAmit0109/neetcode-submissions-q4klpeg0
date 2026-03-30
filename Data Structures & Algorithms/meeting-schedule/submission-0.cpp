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
        int n = intervals.size();
        // for any two intervals to overlap the mininum of ends of them must be
        // greater than the maximum of the start of them 
        // here we just checking for each interval that we can find the any 
        // other overlaping interval in the rest of the vector, if we found
        // simply return false
        for(int i = 0; i < n; i++){
            Interval& A = intervals[i];
            for(int j = i+1; j < n; j++){
                Interval& B = intervals[j];
                if(min(A.end, B.end) > max(A.start, B.start)){
                    return false;
                }
            }
        }
        return true;
    }
};
