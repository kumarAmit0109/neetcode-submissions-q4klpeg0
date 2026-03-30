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
    pair<int, int> dfs(TreeNode* root){
        if(root == nullptr){
            return {INT_MIN, 0};
        }
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);
        // ignore negative paths (they reduce sum
        int leftMax = max(left.second, 0); 
        int rightMax = max(right.second, 0); 

        pair<int, int>res;
        // case 1: path passes through this node (left + root + right)
        // case 2: best path already exists in left or right subtree
        res.first = max(root->val + leftMax + rightMax , max(left.first, right.first));
        // best downward path starting from this node
        res.second = root->val + max(leftMax, rightMax);
        return res;
    }
    int maxPathSum(TreeNode* root) {
        // pair includes <maXPathsum through that node, maxDownwardPath strting at that node> 
        pair<int,int>p = dfs(root);
        return p.first;
    }
};
