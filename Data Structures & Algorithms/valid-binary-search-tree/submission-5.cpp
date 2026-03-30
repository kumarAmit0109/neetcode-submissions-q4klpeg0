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
    bool isValidLeftSubtree(TreeNode* root, int limit){
        // for valid right subtree all the members must be less tha the limit
        if(!root){
            return true;
        }

        if(root->val >= limit){
            return false;
        }

        return isValidLeftSubtree(root->left, limit) && isValidLeftSubtree(root->right, limit);
    }
    
    bool isValidRightSubtree(TreeNode* root, int limit){
        // for valid right subtree all the members must be greater than the limit
        if(!root){
            return true;
        }

        if(root->val <= limit){
            return false;
        }

        return isValidRightSubtree(root->left, limit) && isValidRightSubtree(root->right, limit);
    }

    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }

        bool leftAns = isValidLeftSubtree(root->left, root->val);
        bool rightAns = isValidRightSubtree(root->right, root->val);
        return leftAns && rightAns &&
           isValidBST(root->left) &&
           isValidBST(root->right);
    }
};
