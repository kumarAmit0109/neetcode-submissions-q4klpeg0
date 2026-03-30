class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int strt = 0, end = rows * cols - 1;
        while(strt <= end){
            int mid = strt + (end - strt)/2;
            int temp = matrix[mid / cols][mid % cols];
            if(temp == target){
                return true;
            }else if(temp < target){
                strt = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return false;
    }
};
