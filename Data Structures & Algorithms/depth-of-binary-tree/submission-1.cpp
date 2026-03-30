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
        if(root == nullptr){
            return 0;
        }
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        int ans = 0;
        
        while(!st.empty()){
            pair<TreeNode*, int>top = st.top();
            st.pop();
            TreeNode* node = top.first;
            int depth = top.second;
            ans = max(ans, depth);
            if(node->left != nullptr){
                st.push({node->left, depth + 1});  
            }
            if(node->right != nullptr){
                st.push({node->right, depth + 1});  
            }
            // if(node != nullptr){
            //     ans = max(ans, depth);
            //     st.push({node->left, depth + 1});
            //     st.push({node->right, depth + 1});
            // }
        }
        return ans;
    }
};
