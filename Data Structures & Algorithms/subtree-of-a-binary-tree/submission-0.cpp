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
    bool isSameTree(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot){
            return true;
        }

        if(root && subRoot && root->val == subRoot->val){
            return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
        }else{
            return false;
        }
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        // Empty tree is always a subtree
        if(!subRoot){
            return true;
        }

        // If main tree becomes empty → no subtree found
        if(!root){
            return false;
        }

        // Check if trees match starting from this node
        if(isSameTree(root, subRoot)){
            return true;
        }

        // Otherwise check in left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
