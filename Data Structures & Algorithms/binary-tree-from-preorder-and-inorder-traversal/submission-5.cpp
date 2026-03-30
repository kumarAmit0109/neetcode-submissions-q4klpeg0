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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* head = new TreeNode(0); // dummy node to simplify root handling
        TreeNode* curr = head;            // current node pointer
        
        int inIndx = 0, preIndx = 0;
        int n = preorder.size();

        // process all nodes
        while(inIndx < n && preIndx < n){
            
            // create new node from preorder and attach to right
            curr->right = new TreeNode(preorder[preIndx], nullptr, curr->right);

            curr = curr->right; // move to newly created node
            preIndx++;

            // build left subtree until inorder match
            while(preIndx < n && curr->val != inorder[inIndx]){
                
                // create left child
                curr->left = new TreeNode(preorder[preIndx], nullptr, curr);
                
                curr = curr->left; // move down to left child
                preIndx++;
            }

            inIndx++; // left subtree finished, move inorder pointer

            // move back up using temporary right links
            while(curr->right && inIndx < n && curr->right->val == inorder[inIndx]){
                
                TreeNode* prev = curr->right; // store parent
                
                curr->right = nullptr; // remove temporary link
                
                curr = prev; // move back to parent
                
                inIndx++;
            }
        }

        return head->right; // actual root is right child of dummy
    }
};
