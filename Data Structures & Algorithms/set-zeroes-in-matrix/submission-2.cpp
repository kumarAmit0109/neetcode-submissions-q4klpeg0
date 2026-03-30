class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // create separate vectors to keep track of which rows or cols
        // become zero in the end ,
        // so here in first pass we find those rows and cols and in second
        // pass we mark zero in those rows and cols

        vector<bool>isRowZero(rows, false);
        vector<bool>isColZero(cols, false);
        // mark which row and col will become zero
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    isRowZero[i] = true;
                    isColZero[j] = true;
                }
            }
        }

        // mark in matrix now
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(isRowZero[i] || isColZero[j] ){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
