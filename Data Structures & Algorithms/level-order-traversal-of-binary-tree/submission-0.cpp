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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*>que;
        que.push(root);

        while(!que.empty()){
            vector<int>temp;
            int size = que.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node){
                    temp.push_back(node->val);
                    que.push(node->left);
                    que.push(node->right);
                }
            }
            if(!temp.empty()){
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
