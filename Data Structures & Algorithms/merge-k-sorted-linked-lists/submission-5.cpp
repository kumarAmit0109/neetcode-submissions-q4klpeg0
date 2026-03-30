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
    ListNode* divide(vector<ListNode*>& lists, int left, int right){
        if(left > right){
            return nullptr;
        }
        // left == right simply means that only one list left so return 
        if(left == right){
            return lists[left];
        }

        int mid = left + (right - left)/2;
        // recursively divide the lists vector into two halves nd merge them
        ListNode* leftAns = divide(lists, left, mid);
        ListNode* rightAns = divide(lists, mid+1, right);
        return conquer(leftAns, rightAns);
    }

    ListNode* conquer(ListNode* l1, ListNode* l2){
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;

        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        if(l1 != nullptr){
            curr->next = l1;
        }
        if(l2 != nullptr){
            curr->next = l2;
        }
        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        return divide(lists, 0, lists.size() - 1);

    }

};
