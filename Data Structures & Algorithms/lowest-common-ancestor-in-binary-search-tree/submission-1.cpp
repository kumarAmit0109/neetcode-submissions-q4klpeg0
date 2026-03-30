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
        TreeNode* temp = root;

        while(temp != nullptr){
            // if p's and q's val greater than temp's val then go right nd
            // if both smaller then go left and
            // if not the above cases then return temp its our ans
            if(p->val > temp->val && q->val > temp->val){
                temp = temp->right;
            }else if(p->val < temp->val && q->val < temp->val){
                temp = temp->left;
            }else{
                return temp;
            }
        }
        return nullptr;
    }
};
