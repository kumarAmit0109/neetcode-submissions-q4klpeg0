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
        // sort the interval by start value
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a.start < b.start;
        });

        // use minHeap to keep track of the end of the intervals
        priority_queue<int, vector<int>, greater<int>>minHeap;
        // now process each interval if for any interval the start is less
        // than the heap.top() means the interval overlaps so we have to allot the
        // new room else we can use same room
        for(const auto& interval : intervals){
            // for new allocation simply put the end of inteval in heap, nd
            // for using same room remove the top from heap nd push the new end
            // of interval in heap who use the same room
            if(!minHeap.empty() && minHeap.top() <= interval.start){
                minHeap.pop();
            }
            minHeap.push(interval.end);
        }
        return minHeap.size();
    }
};
