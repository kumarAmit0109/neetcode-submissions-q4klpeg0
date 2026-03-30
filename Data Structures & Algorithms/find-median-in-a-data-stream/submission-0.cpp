class MedianFinder {
public:
    vector<int>data;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        data.push_back(num);
    }
    
    double findMedian() {
        sort(data.begin(), data.end());
        int n = data.size();

        // if the number of elements is odd then the median is the middle element
        // else median is the avg of middle two elements
        if(n & 1){
            return data[n/2];
        }else{
            return (data[n/2] + data[n/2 - 1]) / 2.0;
        }
    }
};
