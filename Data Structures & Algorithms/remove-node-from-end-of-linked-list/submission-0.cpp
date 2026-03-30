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
        vector<ListNode*>nodes;
        ListNode* temp = head;
        while(temp != NULL){
            nodes.push_back(temp);
            temp = temp->next;
        }

        int indexRemoved = nodes.size() - n;
        if(indexRemoved == 0){
            return head->next;
        }

        nodes[indexRemoved - 1]->next = nodes[indexRemoved]->next;
        return head;
    }
};
