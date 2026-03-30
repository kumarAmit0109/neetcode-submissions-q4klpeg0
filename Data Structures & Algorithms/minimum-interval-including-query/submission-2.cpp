class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        // Step 1: Sort intervals based on start value
        // So we can process them in order
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        // Step 2: Copy and sort queries
        // We sort queries to process them from smallest to largest
        vector<int> sortedQueries = queries;
        sort(sortedQueries.begin(), sortedQueries.end());
        // This map will store: query -> answer
        map<int, int> res;
        // Min heap comparator:
        // We want smallest interval length at top
        // If lengths equal, smaller end comes first
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            return a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]);
        };
        // Min heap storing: {interval_length, interval_end}
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> minHeap(cmp);
        int i = 0; // pointer to traverse intervals
        // Step 3: Process each query in sorted order
        for (int q : sortedQueries){
            // Add all intervals whose start <= q
            // These intervals might cover q
            while(i < intervals.size() && intervals[i][0] <= q){
                int l = intervals[i][0];
                int r = intervals[i][1];
                // Push interval as {length, end}
                minHeap.push({r - l + 1, r});
                i++;
            }
            // Remove intervals that end before q
            // These cannot cover q anymore
            while(!minHeap.empty() && minHeap.top()[1] < q){
                minHeap.pop();
            }
            // Now heap contains only valid intervals covering q
            // If empty -> no interval covers q → answer = -1
            // Else → top has smallest length
            res[q] = minHeap.empty() ? -1 : minHeap.top()[0];
        }
        // Step 4: Build result array in original query order
        vector<int> result(queries.size());
        for(int j = 0; j < queries.size(); j++){
            result[j] = res[queries[j]];
        }
        return result;
    }
};