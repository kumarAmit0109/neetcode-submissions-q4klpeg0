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
    // Map to store:
    // original node  ->  copied node
    // This helps us:
    // 1) Avoid copying the same node multiple times
    // 2) Correctly connect random pointers
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {

        // 1️⃣ Base case:
        // If the original list is empty,
        // the copied list is also empty.
        if (head == nullptr) {
            return nullptr;
        }

        // 2️⃣ If this node is already copied,
        // return the existing copy from the map.
        // This prevents infinite loops
        // when random pointers form cycles.
        if (mp.count(head)) {
            return mp[head];
        }

        // 3️⃣ Create a new node (copy) with the same value.
        // At this moment, next and random are not set yet.
        Node* copy = new Node(head->val);

        // 4️⃣ Store the mapping from original node to copied node.
        // This is important so future references
        // can directly use this copied node.
        mp[head] = copy;

        // 5️⃣ Recursively copy the next node
        // and connect it to the copied list.
        copy->next = copyRandomList(head->next);

        // 6️⃣ Set the random pointer of the copied node.
        // head->random points to some original node.
        // mp[head->random] gives us its copied version.
        // If head->random is nullptr, this also becomes nullptr.
        copy->random = mp[head->random];

        // 7️⃣ Return the copied node.
        return copy;
    }
};

