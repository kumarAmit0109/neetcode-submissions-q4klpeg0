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
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        // for each node push the node and maxi in the queue
        queue<pair<TreeNode*, int>>que;
        que.push({root, INT_MIN});

        while(!que.empty()){
            pair<TreeNode*,int>frnt = que.front();
            que.pop();
            TreeNode* node = frnt.first;
            int maxi = frnt.second;
            if( node->val >= maxi ){
                cnt++;
                maxi = node->val;
            }
            // if left exists make entry in que with updated maxi
            if(node->left){
                que.push({node->left, maxi});
            }
            // if right exists make entry in que with updated maxi
            if(node->right){
                que.push({node->right, maxi});
            }

        }
        return cnt;
    }
};
