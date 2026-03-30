class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int topRow = 0, botRow = rows - 1;
        // step 1 : find suitable row in which the target might be present
        while(topRow <= botRow){
            int midRow = topRow + (botRow - topRow)/2;
            if(matrix[midRow][cols - 1] < target){
                topRow = midRow + 1;
            }else if(matrix[midRow][0] > target){
                botRow = midRow - 1;
            }else{
                break;
            }
        }

        if (topRow > botRow){
            return false;
        }
        // step 2 : search for the target in the row found in step 1

        int rowFound = (topRow + botRow)/2;
        int left = 0, right = cols - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(matrix[rowFound][mid] == target){
                return true;
            }else if(matrix[rowFound][mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return false;
    }
};
