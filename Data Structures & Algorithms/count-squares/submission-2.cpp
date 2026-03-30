class CountSquares {
    // ptsCount[x][y] → how many times point (x, y) was added
    unordered_map<int, unordered_map<int, int>> ptsCount;
public:
    CountSquares() {}
    // Add a point (x, y)
    void add(vector<int> point) {
        // Increase frequency of this point
        ptsCount[point[0]][point[1]]++;
    }
    // Count number of squares using given point as one corner
    int count(vector<int> point) {
        int res = 0;
        int x1 = point[0], y1 = point[1]; // given point
        // Fix x = x1 and try all possible y values (same vertical line)
        for (auto &[y2, cnt] : ptsCount[x1]) {
            // Calculate side length of square
            int side = y2 - y1;
            // If side = 0 → same point, cannot form square
            if (side == 0) continue;
            // Two possible squares:
            // 1. Right side square (x1 + side)
            // 2. Left side square  (x1 - side)
            int x3 = x1 + side; // right side x-coordinate
            int x4 = x1 - side; // left side x-coordinate
            // For right square:
            // Need points: (x3, y1) and (x3, y2)
            // Multiply counts because duplicates may exist
            res += cnt * ptsCount[x3][y1] * ptsCount[x3][y2];
            // For left square:
            // Need points: (x4, y1) and (x4, y2)
            res += cnt * ptsCount[x4][y1] * ptsCount[x4][y2];
        }
        return res;
    }
};