class MedianFinder {
public:
    // small heap denote the left side which is the maxHeap and 
    // all elements of the smallHeap is smaller than the elements of the
    // large heap which is the minHeap
    priority_queue<int>smallHeap;
    priority_queue<int, vector<int>, greater<int>>largeHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // initially add the element to the smallHeap and then later
        // move it to the appropriate postion
        smallHeap.push(num);
        if(!largeHeap.empty() && smallHeap.top() > largeHeap.top()){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }

        // make sure that the difference in sizes of the smallHeap and largeHeap
        // is not more than 1
        if(smallHeap.size() > largeHeap.size() + 1){
            largeHeap.push(smallHeap.top());
            smallHeap.pop();
        }
        if(largeHeap.size() > smallHeap.size() + 1){
            smallHeap.push(largeHeap.top());
            largeHeap.pop();
        }
    }
    
    double findMedian() {
        // if the sizes of two heaps are equal then the meadian is the average 
        // of minHeap's top and maxHeap's top\
        // in other case the median belongs to those heap whose size is larger
        if(smallHeap.size() == largeHeap.size()){
            return (largeHeap.top() + smallHeap.top())/ 2.0;
        }else if(smallHeap.size() > largeHeap.size()){
            return smallHeap.top();
        }else{
            return largeHeap.top();
        }
    }
};
