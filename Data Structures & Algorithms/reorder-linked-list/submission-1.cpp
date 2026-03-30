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
    void reorderList(ListNode* head) {
        // find mid
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse after mid
        ListNode* second = slow->next;
        ListNode* prev = slow->next = NULL;
        while(second != NULL){
            ListNode* temp = second->next;
            second->next = prev;
            prev = second;
            second = temp;
        }

        // now join first and second part(reverse after mid) alternatively
        ListNode* first = head;
        second = prev;
        while(second != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = second->next;
            first->next = second;
            second->next = temp1;
            first = temp1;
            second = temp2;
        }
    }
};
