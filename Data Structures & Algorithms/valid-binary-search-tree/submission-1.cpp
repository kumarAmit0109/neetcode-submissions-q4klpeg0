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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }

        queue<tuple<TreeNode*, int, int>> que;
        que.push(make_tuple(root, INT_MIN, INT_MAX));

        while(!que.empty()){
            auto [node, left, right] = que.front();
            que.pop();

            if(!(left < node->val && node->val < right)){
                return false;
            }

            if(node->left){
                que.push(make_tuple(node->left, left, node->val));
            }
            if(node->right){
                que.push(make_tuple(node->right, node->val, right));
            }
        }
        return true;
    }
};
