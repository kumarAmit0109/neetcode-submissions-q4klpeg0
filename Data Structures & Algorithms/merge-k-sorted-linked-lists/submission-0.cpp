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
        vector<int>nodes;
        for(ListNode* lst : lists){
            while(lst != nullptr){
                nodes.push_back(lst->val);
                lst = lst->next;
            }
        }

        // sort the nodes array
        sort(nodes.begin(), nodes.end());

        // create a new list with the help of the sorted node array
        ListNode* res = new ListNode(0);
        ListNode* curr = res;
        for(int node: nodes){
            curr->next = new ListNode(node);
            curr = curr->next;
        }
        return res->next;

    }
};
