class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse the matrix vertically,
        // below line flips the matrix upside down, so rows become reversed
        reverse(matrix.begin(), matrix.end());

        // now transpose the matrix
        for(int i = 0; i < matrix.size(); i++){
            for(int j = i+1; j < matrix[i].size(); j++){
                // swap (i,j)th element with (j,i)
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
