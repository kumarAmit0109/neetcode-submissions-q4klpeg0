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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // If tree is empty, return empty result
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int len = que.size();
            // Since queue only contains valid nodes,
            // the last node in queue is the rightmost node of this level
            TreeNode* rightSide = que.back();

            for(int i = 0; i < len; i++){
                TreeNode* node = que.front();
                que.pop();
                // Push only non-null children
                if(node->left){
                    que.push(node->left);
                }

                if(node->right){
                    que.push(node->right);
                }
            }

            // Add the rightmost node of this level
            ans.push_back(rightSide->val);
        }

        return ans;
    }
};
