/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr){
            return nullptr;
        }
        // Interleave copy nodes
        Node* temp = head;
        while(temp != nullptr){
            Node* copy = new Node(temp -> val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next; 
        }
        // Assign random pointers
        Node* copyHead = head->next;
        temp = head;
        while(temp != nullptr){
            if(temp->random != nullptr){
                temp->next->random = temp->random->next;
            }
            temp = temp->next->next;
        }
        // Unweave the lists
        temp = head;
        while(temp != nullptr){
            Node* copy = temp->next;
            temp->next = copy->next;
            if(copy->next != nullptr){
                copy->next = copy->next->next;
            } 
            temp = temp->next;
        }
        return copyHead;
    }
};
