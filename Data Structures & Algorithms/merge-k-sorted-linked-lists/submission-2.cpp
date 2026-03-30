/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(true){
            int minNode = -1;
            for(int i = 0; i < lists.size(); i++){
                if(!lists[i]){
                    continue;
                }

                if(minNode == -1 || lists[minNode]->val > lists[i]->val){
                    minNode = i;
                }
            }
            // minNode == -1 , indicates that the nothing is left in the lists all lists are
            // traversed sucessfully 
            if(minNode == -1){
                break;
            }
            curr->next = lists[minNode];
            // minNode is only set when a non-null list exists, so no need to checking lists[minNode]
            //  is null or not before moving forward
            lists[minNode] = lists[minNode]->next;
            curr = curr->next;
        }
        return dummy->next;
    }
};
