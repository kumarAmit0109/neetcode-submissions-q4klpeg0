/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isBalanced(TreeNode* root) {

        // Stack to simulate recursive DFS (postorder)
        stack<TreeNode*> st;

        // Pointer used for traversal
        TreeNode* node = root;

        // Keeps track of the last processed node
        // Helps us know whether the right subtree is already done
        TreeNode* last = nullptr;

        // Stores height of each node after it is processed
        unordered_map<TreeNode*, int> depths;

        // Continue until all nodes are processed
        while (!st.empty() || node != nullptr) {

            // Go as left as possible (like recursive DFS)
            if (node != nullptr) {
                st.push(node);
                node = node->left;
            } 
            else {
                // Peek the top node from stack
                node = st.top();

                // If right child is null OR right subtree is already processed
                // then we can process the current node (postorder step)
                if (node->right == nullptr || last == node->right) {

                    st.pop();

                    // Get heights of left and right subtrees
                    int leftHeight = depths[node->left];
                    int rightHeight = depths[node->right];

                    // If height difference is more than 1, tree is unbalanced
                    if (abs(leftHeight - rightHeight) > 1) {
                        return false;
                    }

                    // Store height of current node
                    depths[node] = 1 + max(leftHeight, rightHeight);

                    // Mark this node as last processed
                    last = node;

                    // Set node to nullptr to force backtracking
                    node = nullptr;
                } 
                else {
                    // Right subtree not processed yet, go right
                    node = node->right;
                }
            }
        }

        // If no imbalance found, tree is balanced
        return true;
    }
};
