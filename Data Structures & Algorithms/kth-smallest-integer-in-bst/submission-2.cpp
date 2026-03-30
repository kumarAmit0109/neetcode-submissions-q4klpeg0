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
    void inorder(TreeNode* root, int& count, int& ans){
        if(root == nullptr){
            return;
        }
        inorder(root->left, count, ans);
        count--;
        if(count == 0){
            ans = root->val;
            return;
        }
        inorder(root->right, count, ans);
    }
    int kthSmallest(TreeNode* root, int k) {
        int count = k;
        int ans = -1;
        inorder(root, count, ans);
        return ans;
    }
};
