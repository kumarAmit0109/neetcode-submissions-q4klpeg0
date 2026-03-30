class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // create a copy of original matrix and first manipulate
        //  this copy based on zero cell encounter in the original matrix
        vector<vector<int>> temp = matrix;

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    // mark all row element zero in temp
                    for(int k = 0; k < cols; k++){
                        temp[i][k] = 0;
                    }
                    // mark all column element zero in temp
                    for(int k = 0; k < rows; k++){
                        temp[k][j] = 0;
                    }
                }
            }
        }

        // finally copy temp to original matrix
        // for(int i = 0; i < rows; i++){
        //     for(int j = 0; j < cols; j++){
        //         matrix[i][j] = temp[i][j];
        //     }
        // }
        matrix = temp;
    }
};
