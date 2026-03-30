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
    int diameterOfBinaryTree(TreeNode* root) {

        // Map to store: node -> {height, diameter}
        unordered_map<TreeNode*, pair<int, int>> mp;

        // Base case: null node has height = 0 and diameter = 0
        mp[nullptr] = {0, 0};

        // Stack to simulate recursive postorder traversal
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {

            // Look at the top node (do not pop yet)
            TreeNode* node = st.top();

            // If left child exists and is not processed yet, go left
            if (node->left && mp.find(node->left) == mp.end()) {
                st.push(node->left);
            }
            // if right child exists and is not processed yet, go right
            else if (node->right && mp.find(node->right) == mp.end()) {
                st.push(node->right);
            }
            // Else: both children are processed, now process this node
            else {
                st.pop();

                // Get height and diameter of left subtree
                auto [leftHeight, leftDiameter] = mp[node->left];

                // Get height and diameter of right subtree
                auto [rightHeight, rightDiameter] = mp[node->right];

                // Height of current node = 1 + max height of children
                int height = 1 + max(leftHeight, rightHeight);

                // Diameter can be:
                // 1) path passing through this node
                // 2) best diameter in left subtree
                // 3) best diameter in right subtree
                int diameter = max(
                    leftHeight + rightHeight,
                    max(leftDiameter, rightDiameter)
                );

                // Store result for current node
                mp[node] = {height, diameter};
            }
        }

        // Diameter of entire tree is stored at root
        return mp[root].second;
    }
};
