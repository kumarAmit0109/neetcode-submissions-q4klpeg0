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
    int maxDepth(TreeNode* root) {
        queue<TreeNode*>que;
        if(root != nullptr){
            que.push(root);
        }
        int level = 0;
        
        while(!que.empty()){
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* frnt = que.front();
                que.pop();
                if(frnt->left != nullptr){
                    que.push(frnt->left);
                }
                if(frnt->right != nullptr){
                    que.push(frnt->right);
                }
            }
            level++;
        }
        return level;
    }
};
