class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (!root) return true;

        bool leftBalanced = isBalanced(root->left);
        bool rightBalanced = isBalanced(root->right);

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (abs(leftHeight - rightHeight) <= 1 
            && leftBalanced 
            && rightBalanced) {
            return true;
        }
        return false;
    }
};
