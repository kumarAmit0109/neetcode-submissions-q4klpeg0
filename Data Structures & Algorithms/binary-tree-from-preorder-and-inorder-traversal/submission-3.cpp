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
  /*
    dfs builds the tree recursively using preorder and inorder traversal.

    preorder → tells which node to create next
    inorder  → tells when to stop building subtree

    inIndx  → current position in inorder
    preIndx → current position in preorder
    limit   → boundary value that tells when subtree ends
    */
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& inIndx, int& preIndx, int limit){
        if(preIndx >= preorder.size()){
            return nullptr;
        }
        // If current inorder value equals limit,
        // it means we finished building this subtree
        if(inorder[inIndx] == limit){
            inIndx++;
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preIndx++]);
        /*
        Now build left subtree
        limit becomes root->val
        Why?
        Because inorder structure is:
        Left → Root → Right
        So when inorder reaches root->val,
        left subtree must stop
        */
        root->left = dfs(preorder, inorder, inIndx, preIndx, root->val);
        /*
        Now build right subtree
        limit remains same as parent's limit
        This allows building nodes until
        reaching parent's boundary
        */
        root->right = dfs(preorder, inorder, inIndx, preIndx, limit);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inIndx = 0, preIndx = 0;
        return dfs(preorder, inorder, inIndx, preIndx, INT_MAX);
    }
};
