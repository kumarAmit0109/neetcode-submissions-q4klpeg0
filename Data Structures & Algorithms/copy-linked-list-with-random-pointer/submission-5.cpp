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
        // Create copy nodes and attach them using the random pointer
        Node* temp = head;
        while(temp != nullptr){
            Node* copy = new Node(temp->val);
            copy->next = temp->random; // store old random temporarily
            temp->random = copy;  // link original -> copy
            temp = temp->next;
        }

        // Assign correct random pointers to copied nodes
        Node* copyHead = head->random;
        temp = head;
        while(temp != nullptr){
            Node* copy = temp->random;
            // copy.random = copy of original.random
            copy->random = (copy->next != nullptr) ? copy->next->random : nullptr;
            temp = temp->next;
        }
        
        //  Separate original list and copied list
        temp = head;
        while(temp != nullptr ){
            Node* copy = temp->random;
            temp->random = copy->next;
            // set next pointer of copied list
            copy->next = (temp->next != nullptr) ? temp->next->random : nullptr;
            temp = temp->next;
        }
        return copyHead;
    }
};
