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
        unordered_map<Node*, Node*>oldToCopy;
        // if nxt or random is nullptr, map will return nullptr without any extra check
        oldToCopy[nullptr] = nullptr;

        Node* cur = head;
        while(cur != nullptr){
            // if map doesnt have copy, create a empty copy node nd store it in map
            if(oldToCopy.find(cur) == oldToCopy.end()){
                oldToCopy[cur] = new Node(0);
            }
            // Copy the value from original node to copied node
            oldToCopy[cur]->val = cur->val;

            // if map doesnt have nxt, create a empty nxt node nd store it in map
            if (oldToCopy.find(cur->next) == oldToCopy.end()) {
                oldToCopy[cur->next] = new Node(0);
            }
            //Connect copied node's next to the copied version of original next
            oldToCopy[cur]->next = oldToCopy[cur->next];

            // if map doesnt have random, create a empty random node nd store it in map
            if(oldToCopy.find(cur->random) == oldToCopy.end()){
                oldToCopy[cur->random] = new Node(0);
            }
            //Connect copied node's random to the copied version of original random
            oldToCopy[cur]->random = oldToCopy[cur->random];
            cur = cur->next;
        } 
        return oldToCopy[head];
    }
};
