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
    void solve(TreeNode* root, int& cnt, int maxi){
        if(root == nullptr){
            return;
        }
        if(root->val >= maxi){
            cnt++;
            maxi = root->val;
        }
        solve(root->left, cnt, maxi);
        solve(root->right, cnt, maxi);

    }
    int goodNodes(TreeNode* root) {
        int cnt = 0;
        int maxi = INT_MIN;
        // approach is pretty simple keep track of maxi at each call
        // nd if the data of root is greater or equal to maxi yet then
        // its a good node update maxi nd call for childrens
        solve(root, cnt, maxi);
        return cnt;
    }
};
