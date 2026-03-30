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
        vector<int>ans;
        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()){
            TreeNode* rightSide = nullptr;
            // Number of nodes in current level
            int len = que.size();
            // Process all nodes of this level
            for(int i = 0; i < len; i++){
                // Get front node and remove it from queue
                TreeNode* node = que.front();
                que.pop();
                if(node){
                    // Keep updating rightSide
                    // After loop ends, this will contain
                    // the LAST node of this level
                    rightSide = node;
                    // Push left child into queue (for next level)
                    if(node->left)
                        que.push(node->left);
                    // Push right child into queue (for next level)
                    if(node->right)
                        que.push(node->right);
                    // NOTE:
                    // Since we push left first and right second,
                    // nodes are processed left → right.
                    // So the last node processed in this level
                    // is the rightmost node.
                }
            }

            // After finishing this level,
            // add the rightmost node value to answer
            if(rightSide){
                ans.push_back(rightSide->val);
            }
        }

        return ans;
    }
};
