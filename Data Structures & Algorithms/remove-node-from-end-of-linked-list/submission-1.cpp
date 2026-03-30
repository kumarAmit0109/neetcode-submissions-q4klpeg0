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
        int cnt = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }

        int indexRemoved = cnt - n;

        if(indexRemoved == 0){
            return head->next;
        }

        temp = head;
        for(int i = 0; i < cnt - 1; i++){
            if((i+1) ==  indexRemoved){
                temp->next = temp->next->next;
                break;
            }
            temp = temp->next;
        }
        return head;
    }

};
