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
    ListNode* getKthNode(ListNode* curr, int k){
        while(curr != nullptr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* grpPrev = dummy;

        while(true){
            // find kth node
            ListNode* kthNode = getKthNode(grpPrev, k);
            if(kthNode == nullptr){
                break;
            }

            ListNode* grpNext = kthNode->next;
            // reverse the node between grpPrev and grpNext
            ListNode* prev = kthNode->next;
            ListNode* curr = grpPrev->next;

            while(curr != grpNext){
                ListNode* nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }
            // old first node of the group (will become the last after the reverse)
            ListNode* grpTail = grpPrev->next;
            // connect previous group to the new head of this reversed group
            grpPrev->next = kthNode;
            // move grpPrev to the tail, so next group starts after it
            grpPrev = grpTail;
        }
        return dummy->next;
    }
};
