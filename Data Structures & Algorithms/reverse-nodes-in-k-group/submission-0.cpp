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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        // check if there are at least k nodes
        for(int i = 0; i < k; i++){
            // if fewer nodes than k nodes so leave as it is nd return
            if(curr == nullptr){
                return head;
            }
            curr = curr->next;
        }

        // recursively process the rest strting from curr (node after k nodes)
        ListNode* remainder = reverseKGroup(curr, k);

        // reverse the current group of k nodes
        ListNode* prev = remainder; // tail of reversed grp should connect to remainder
        curr = head;
        for(int i = 0; i < k; i++){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // prev is new head of this reversed group
        return prev;
     
    }
};
