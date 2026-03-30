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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1, head);
        ListNode* left = dummy;
        ListNode* right = head;

        // move right pointer to n distance from strt
        while( n > 0){
            right = right->next;
            n--;
        }

        // now while maintaining the n distance move right nd left pointer 
        // by one step, key is when the right pointer reaches the end, left is
        // adready at the (n-1)th distance 
        while(right != NULL){
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;
        return dummy->next;

    }
};
