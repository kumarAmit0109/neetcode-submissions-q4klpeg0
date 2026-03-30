class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // check whether its possible to divide or not
        if (hand.size() % groupSize != 0){
            return false;
        }

        // make a frequency map for elements
        unordered_map<int, int> count;
        for (int num : hand){
            count[num]++;
        } 

        // sort the hand vector so that we can form grouping starting from
        // the smallest available element
        sort(hand.begin(), hand.end());

        // now iterate through each card if curr card count is zero so skip
        // if not then start creating a grp from that postion nd take
        // element equal to grp size nd decrease the count of that element
        for (int num : hand) {
            if (count[num] > 0) {
                for (int i = num; i < num + groupSize; i++) {
                    // if count of element is already zero then grouping
                    // is not possible return false, in othe case simply decrease
                    // the count
                    if (count[i] == 0){
                        return false;
                    }
                    count[i]--;
                }
            }
        }
        return true;
    }
};