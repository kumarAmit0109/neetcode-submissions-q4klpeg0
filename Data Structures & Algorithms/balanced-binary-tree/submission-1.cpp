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
    pair<bool, int> dfs(TreeNode* root){
        if(root == nullptr){
            return {true, 0};
        }

        pair<bool, int>leftAns = dfs(root->left);
        pair<bool, int>rightAns = dfs(root->right);
        int leftHeight = leftAns.second;
        int rightHeight = rightAns.second;

        int leftBalanced = leftAns.first;
        int rightBalanced = rightAns.first;

        pair<bool, int>temp; 
        temp.second = max(leftHeight, rightHeight) + 1;
        temp.first = leftBalanced && rightBalanced && (abs(leftHeight - rightHeight) <=1);
        return temp;

    }
    bool isBalanced(TreeNode* root) {
        return dfs(root).first;
    }
};
