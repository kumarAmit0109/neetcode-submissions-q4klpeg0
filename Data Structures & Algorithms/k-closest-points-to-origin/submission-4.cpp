class Solution {
public:

    // calculate squared distance from origin (0,0)
    int euclideanDistance(vector<int>& point){
        return point[0]*point[0] + point[1]*point[1];
    }

    // partition function similar to QuickSort
    int partition(vector<vector<int>>& points, int left, int right){
        
        int pivotIndx = right; // choose last element as pivot
        int pivotDist = euclideanDistance(points[pivotIndx]);

        int i = left; // position to place smaller elements

        for(int j = left; j < right; j++){
            
            // if current point is closer than pivot
            if(euclideanDistance(points[j]) <= pivotDist){
                
                swap(points[i], points[j]); // move closer point to left
                i++;
            }
        }

        // place pivot in correct position
        swap(points[i], points[right]);

        return i; // return pivot's final index
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        int left = 0;
        int right = points.size() - 1;

        while(true){

            int pivot = partition(points, left, right);

            // if pivot is at kth position, stop
            if(pivot == k-1){
                break;
            }
            else if(pivot < k){
                left = pivot + 1; // search right side
            }
            else{
                right = pivot - 1; // search left side
            }
        }

        // first k elements are k closest points
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};