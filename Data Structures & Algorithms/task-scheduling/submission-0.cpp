class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Step 1: Count frequency of each task (A-Z)
        vector<int> count(26, 0);
        for (char task : tasks) {
            count[task - 'A']++;   // Map 'A'->0, 'B'->1 ... and count occurrences
        }
        // Step 2: Max heap to always pick the task with highest remaining frequency
        priority_queue<int> maxHeap;
        for(int cnt : count){
            if(cnt > 0){
                maxHeap.push(cnt); // Push only tasks that appear
            }
        }
        int time = 0;  // This represents the CPU time units
        // Queue to keep tasks that are in cooldown
        // pair = {remaining_count, time_when_it_can_be_used_again}
        queue<pair<int, int>> q;
        // Run until both heap and cooldown queue become empty
        while(!maxHeap.empty() || !q.empty()){
            time++; // move to next unit of time
            if(maxHeap.empty()) {
                // If no task available to execute,
                // jump time directly to when next task becomes available
                time = q.front().second;
            }else{
                // Execute the most frequent task
                int cnt = maxHeap.top() - 1; // one instance executed
                maxHeap.pop();
                // If the task still has remaining executions
                if (cnt > 0) {
                    // Put it into cooldown queue
                    // It will be available again after n intervals
                    q.push({cnt, time + n});
                }
            }
            // If any task cooldown finishes at current time,
            // move it back to the heap so it can be executed again
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        // Total time required to complete all tasks
        return time;
    }
};