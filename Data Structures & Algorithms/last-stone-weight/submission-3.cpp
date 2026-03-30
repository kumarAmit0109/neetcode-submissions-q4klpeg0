class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(), stones.end());
        int n = stones.size();

        while(n > 1){
            int diff = stones[n-1] - stones[n-2];
            n = n - 2;

            // if the difference is not equal to 0 then using binary search find the
            // correct pos in order to insert the diff, afer that shift the rest element 
            // of stones vector one step right from that found postion in the previous step

            if(diff > 0){
                int left = 0, right = n;
                while(left < right){
                    int mid = (left + right) / 2;
                    if(stones[mid] < diff){
                        left = mid + 1;
                    }else{
                        right = mid;
                    }
                }
                // move one step right inorder to make the space for the diff element
                int pos = left;
                stones.push_back(0);
                for(int i = n+1; i > pos; i--){
                    stones[i] = stones[i-1];
                }
                stones[pos] = diff;
                n++;
            }
        }
        return n > 0 ? stones[0] : 0;
    }
};
