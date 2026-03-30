class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        vector<int> res;
        // Direction vectors in clockwise order:
        // Right  → (0, +1)
        // Down   ↓ (+1, 0)
        // Left   ← (0, -1)
        // Up     ↑ (-1, 0)
        vector<pair<int,int>> directions = {
            {0, 1},    // move right
            {1, 0},    // move down
            {0, -1},   // move left
            {-1, 0}    // move up
        };

        // steps[0] → number of horizontal moves remaining
        // steps[1] → number of vertical moves remaining
        //
        // Initially:
        // Horizontal moves = number of columns
        // Vertical moves   = number of rows - 1
        //
        // Why rows - 1?
        // Because after moving right across the top row,
        // we should not count that row again.
        vector<int> steps = {
            matrix[0].size(),      // horizontal moves
            matrix.size() - 1      // vertical moves
        };

        // Start just outside the matrix so first move enters (0,0)
        int row = 0;
        int col = -1;

        // d = direction index
        // 0 → right
        // 1 → down
        // 2 → left
        // 3 → up
        int d = 0;

        // Continue while current direction still has steps remaining
        while (steps[d % 2]) {

            // Move in current direction for allowed steps
            for (int i = 0; i < steps[d % 2]; i++) {

                // Update position using direction vector
                row += directions[d].first;
                col += directions[d].second;

                // Add current element to result
                res.push_back(matrix[row][col]);
            }

            // After finishing this direction,
            // reduce the step count for that dimension
            steps[d % 2]--;

            // Rotate direction clockwise
            // 0 → 1 → 2 → 3 → 0 ...
            d = (d + 1) % 4;
        }

        return res;
    }
};