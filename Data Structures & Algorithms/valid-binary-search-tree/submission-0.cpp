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
    bool valid(TreeNode* node, int left, int right){
        if(!node){
            return true;
        }
        // check whether our node lies within the range or not
        if(!(left < node->val && node->val<right)){
            return false;
        }
        
        // recursively check for leftSubTree nd rightSubtree plus
        // update the ranges accordingly
        bool leftCheck = valid(node->left, left, node->val); 
        bool rightCheck = valid(node->right, node->val, right); 
        return leftCheck && rightCheck;
    }
    bool isValidBST(TreeNode* root) {
        // initially valid range for root we can consider as , (INT_MIN, INT_MAX)
        return valid(root, INT_MIN, INT_MAX);
    }
};
