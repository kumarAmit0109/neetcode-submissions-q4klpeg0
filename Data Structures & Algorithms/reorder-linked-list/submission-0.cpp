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
        if(head == nullptr){
            return;
        }

        vector<ListNode*>nodes;
        ListNode* temp = head;

        while(temp){
            nodes.push_back(temp);
            temp = temp->next;
        }
        int strt = 0, end = nodes.size() - 1;
        while(strt < end){
            nodes[strt]->next = nodes[end];
            strt++;
            if(strt >= end){
                break;
            }
            nodes[end]->next = nodes[strt];
            end--;
        }
        nodes[strt]->next = nullptr;
    }
};
