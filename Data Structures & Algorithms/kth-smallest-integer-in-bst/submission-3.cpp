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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>st;
        TreeNode* temp = root;
        
        // iterative way of doing inorder
        while(!st.empty() || temp!= nullptr){
            // go to the leftmost node
            // push all left nodes into stack
            while(temp != nullptr){
                st.push(temp);
                temp = temp->left;
            }
            // now leftmost node is reached
            // top of stack is the next smallest element
            temp = st.top();
            st.pop();
            k--;
            if(k == 0){
                return temp->val;
            }
            // move to right subtree to continue inorder traversal
            temp = temp->right;
        }
        return -1;
    }
};
