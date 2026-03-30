class CountSquares {
private:
    // Stores how many times a point (x, y) appears
    unordered_map<long, int> ptsCount;
    // Stores all added points (including duplicates)
    vector<vector<int>> pts;
    // Converts (x, y) into a unique single number (key)
    // so we can store it in hashmap easily
    long getKey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }
public:
    CountSquares() {
    }
    // Add a new point
    void add(vector<int> point) {
        long key = getKey(point[0], point[1]);
        // Increase count of this point (handles duplicates)
        ptsCount[key]++;
        // Store the point in list
        pts.push_back(point);
    }

    // Count number of squares with given point as one corner
    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1]; // given point
        // Try every previously added point as a possible diagonal point
        for (const auto& pt : pts) {
            int x = pt[0], y = pt[1];
            // Check if (px, py) and (x, y) can form a diagonal of a square
            // Conditions:
            // 1. Distance in x and y must be equal → forms a square
            // 2. Points should not be in same row or column
            if (abs(py - y) != abs(px - x) || x == px || y == py) 
                continue;
            // Now we have diagonal points:
            // (px, py) and (x, y)
            // Other two required points to complete square:
            // (x, py) and (px, y)
            // Multiply their counts because duplicates are possible
            res += ptsCount[getKey(x, py)] * ptsCount[getKey(px, y)];
        }
        return res;
    }
};