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
    ListNode* solve(ListNode* root, ListNode* curr) {

    // 1️⃣ Base case:
    // If curr has reached past the last node,
    // we have gone till the end of the list.
    // Start returning back and give root (front pointer).
    if (curr == nullptr) {
        return root;
    }

    // 2️⃣ Go deeper first (move curr forward).
    // No reordering happens here.
    // Actual work happens while coming back.
    root = solve(root, curr->next);

    // 3️⃣ If root becomes nullptr,
    // it means reordering is already finished.
    // Stop everything.
    if (root == nullptr) {
        return nullptr;
    }

    // 4️⃣ Check if we reached the middle of the list.
    // - root == curr  → odd length list (same node)
    // - root->next == curr → even length list (crossed nodes)
    if (root == curr || root->next == curr) {

        // Cut the list to avoid cycle
        curr->next = nullptr;

        // Return nullptr to signal:
        // "Stop reordering further"
        return nullptr;
    }

    // 5️⃣ Normal reordering case:
    // Save the next front node
    ListNode* temp = root->next;

    // Place curr (from end) after root (from front)
    root->next = curr;

    // Connect curr to the remaining front part
    curr->next = temp;

    // 6️⃣ Move root forward for the next pairing
    // temp becomes the new root
    return temp;
    }

    void reorderList(ListNode* head) {
        head = solve(head, head->next);
    }
};
