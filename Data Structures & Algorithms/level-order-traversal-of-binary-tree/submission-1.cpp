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
    void dfs(TreeNode* node, int depth, vector<vector<int>>& ans){
        if(node == nullptr){
            return;
        }
        // If we are visiting this depth for the first time,
        // create a new vector for this level
        if(ans.size() == depth){
            ans.push_back(vector<int>());
        }
        // Add current node value to its corresponding level
        ans[depth].push_back(node->val);
        // Recurse for left subtree, increase depth
        dfs(node->left, depth + 1, ans);
        // Recurse for right subtree, increase depth
        dfs(node->right, depth + 1, ans);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        // Start DFS from root at depth 0
        dfs(root, 0, ans);
        return ans;
    }
};
