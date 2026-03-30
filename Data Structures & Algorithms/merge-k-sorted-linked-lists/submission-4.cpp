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
        if(lists.empty()){
            return nullptr;
        }
        // The lambda comparator
        auto compare = [](ListNode* a, ListNode* b){
            return a->val > b->val;
        };
        // Since lambdas have unique compiler-generated types, 
        // we often use decltype(lambda_variable) to refer to that type.
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)>minHeap(compare);
        // Constructor argument: minHeap(compare)
        // The priority queue needs an instance of the comparator to use internally. 
        // For lambdas (which are objects), we pass the lambda instance as a constructor argument.
        for(ListNode* list : lists){
            if(list != nullptr){
                minHeap.push(list);
            }
        }

        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            minHeap.pop();
            cur->next = node;
            cur = cur->next;

            node = node->next;
            if (node != nullptr) {
                minHeap.push(node);
            }
        }
        return dummy->next;
    }
};
