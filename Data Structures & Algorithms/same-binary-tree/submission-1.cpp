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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        // Stack to store pairs of nodes to compare
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({p, q});

        while (!st.empty()) {

            auto [node1, node2] = st.top();
            st.pop();

            // If both nodes are null, this pair matches
            if (!node1 && !node2) {
                continue;
            }

            // If only one is null OR values differ, trees are not same
            if (!node1 || !node2 || node1->val != node2->val) {
                return false;
            }
            // Push left children
            st.push({node1->left, node2->left});
            
            // Push right children
            st.push({node1->right, node2->right});

            
        }

        // All nodes matched
        return true;
    }
};
