class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        // Step 1: Find the maximum stone weight
        // This helps us know how big our bucket array should be
        int maxStone = 0;
        for(int stone : stones){
            maxStone = max(maxStone, stone);
        }

        // Step 2: Create bucket (frequency array)
        // bucket[w] = how many stones exist with weight w
        vector<int> bucket(maxStone + 1, 0);
        
        // Fill the bucket with stone counts
        for(int stone : stones){
            bucket[stone]++;
        }

        // Step 3: Initialize pointers to track the two heaviest stones
        // first = heaviest stone
        // second = second heaviest stone
        int first = maxStone, second = maxStone;

        // Step 4: Start checking from heaviest stone downwards
        while(first > 0){

            // If number of stones at this weight is even,
            // they destroy each other in pairs
            // Example: 4 and 4 → both gone
            if(bucket[first] % 2 == 0){
                first--; // move to next smaller weight
                continue;
            }

            // Step 5: Find the second heaviest stone
            // Start from either first-1 or previous second
            int j = min(first - 1, second);

            // Move down until we find a weight that exists
            while(j > 0 && bucket[j] == 0){
                j--;
            }

            // If no second stone found,
            // then current first stone is the answer
            if(j == 0){
                return first;
            }

            // Step 6: Smash the two stones
            second = j;

            // Remove one stone of weight "first"
            bucket[first]--;

            // Remove one stone of weight "second"
            bucket[second]--;

            // Add the new stone with weight (first - second)
            bucket[first - second]++;

            // Step 7: Update first pointer
            // New heaviest could be the difference OR second
            first = max(first - second, second);
        }

        // If no stones remain, return 0
        return first;
    }
};