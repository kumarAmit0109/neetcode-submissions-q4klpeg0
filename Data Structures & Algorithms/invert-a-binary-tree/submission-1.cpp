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
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return nullptr;
        }
        swap(root->left, root->right);
// In C++, you’re allowed to ignore a function’s return value. No error.
// The purpose of the recursive calls is to perform work (invert subtrees), 
// not to give you a new pointer. Since the subtrees are inverted in-place, you don’t have to capture what’s returned.
        // invertTree(root->left);
        // invertTree(root->right);

        root->left  = invertTree(root->left);
        root->right = invertTree(root->right);
// This is also valid, but in this specific function, it’s redundant, because:

// invertTree(root->left) returns the same root->left pointer you passed (after in-place inversion).
// So you’re basically assigning root->left back to itself.

// This pattern (assigning the return value) is needed for functions that might change which node is 
// the root of the subtree (like rotations in AVL/Red-Black trees, or some deletion operations). But here, the root of the subtree doesn’t change—just its children flip

        return root;
    }
};
