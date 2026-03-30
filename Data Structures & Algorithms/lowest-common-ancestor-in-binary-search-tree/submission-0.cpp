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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q){
            return nullptr;
        }
        // if both nodes are smaller than root node means , lca must be in left subtree
        if(max(p->val, q->val) < root->val){
            return lowestCommonAncestor(root->left, p, q);
        }else if(min(p->val, q->val) > root->val){
        // if both nodes are greater than root node means , lca must be in right subtree
            return lowestCommonAncestor(root->right, p, q);
        }else{
            // One node is on left and the other is on right. Or root equals one of them
            // That means: This root is the split point.
            // This is the lowest common ancestor. so we return the root 
            return root;
        }
    }
};
