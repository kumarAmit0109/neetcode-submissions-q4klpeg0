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
    int res = INT_MIN;
     /*
    getMax returns the maximum path sum starting from this node
    and going DOWNWARD only (either left or right, not both).

    This is important because when returning to parent,
    we can only take one branch, not both.
    */
    int getMax(TreeNode* root){
        if(!root){
            return 0;
        }
        /*
        Path including current node and ONE subtree

        Why only one?
        Because when returning upward,
        path cannot split into two directions.
        */
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + max(left, right);
           /*
        If path becomes negative, ignore it (return 0)

        Because negative path will reduce total sum.
        So better not include it.
        */
        return max(0, path);
    }

    /*
    dfs checks each node as a potential "peak"
    where path goes left → node → right
    */
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        int left = getMax(root->left);
        int right = getMax(root->right);
        res = max(res, root->val + left + right);
        dfs(root->left);
        dfs(root->right);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};
