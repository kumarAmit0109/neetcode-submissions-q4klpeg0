class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // If the zero is in first row, we cannot use matrix[0][0] for marking
        // because it is shared. So we use this separate variable.         
        bool rowZero = false;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                // for marking columns we use the first row 
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    // for marking the rows we use first column elements except [0][0]th element
                    //  which is replaced by the rowZero variable to avoid duplicacy
                   if(i > 0){
                        matrix[i][0] = 0;
                    }else{
                        rowZero = true;
                    }
                }
                
            }
        }

        // after marking is done leave the first row and col as it as and 
        // process other as if we strt with them then , it may interfare with
        // rest element nd produce wrong result

        for(int i = 1; i < rows; i++){
            for(int j = 1; j < cols; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        }

        // if matrix[0][0] is zero means mark all the element in first col 0
        if(matrix[0][0] == 0){
            for(int i = 0; i < rows; i++){
                matrix[i][0] = 0;
            }
        }

        // if rowZero is true means mark all the first row as zero
        if(rowZero){
            for(int j = 0; j < cols; j++){
                matrix[0][j] = 0;
            }
        }
    }
};
