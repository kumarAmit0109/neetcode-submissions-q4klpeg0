class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // create a new matrix and place the element one by one there
        int n = matrix.size();
        vector<vector<int>> rotated(n, vector<int>(n));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                rotated[j][n - 1 - i] = matrix[i][j];
            }
        }

        // assign new created matrix to older one
        matrix = rotated;
    }
};
