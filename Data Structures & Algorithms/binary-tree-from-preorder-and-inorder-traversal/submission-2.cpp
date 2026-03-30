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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& indx, int inorderStrt, int inorderEnd, int size, unordered_map<int, int>&mp){
        if(indx == size || inorderStrt > inorderEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[indx]);
        indx++;

        int mid = mp[root->val];
        root->left = solve(preorder, inorder, indx, inorderStrt, mid-1, size, mp);
        root->right = solve(preorder, inorder, indx, mid+1, inorderEnd, size, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int indx = 0, inorderStrt = 0, inorderEnd = inorder.size()-1;
        unordered_map<int,int>mp;

        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        return solve(preorder, inorder, indx, inorderStrt, inorderEnd, preorder.size(), mp);    
    }
};
