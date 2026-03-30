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

class Codec {
public:

    void buildString(TreeNode* root, string &res) {
        
        if (root == nullptr) {
            res += "N,";            // mark null
            return;
        }

        res += to_string(root->val) + ",";  // store value
        
        buildString(root->left, res);       // serialize left
        buildString(root->right, res);      // serialize right
    }

    string serialize(TreeNode* root) {
        string res;
        buildString(root, res);
        return res;
    }

    TreeNode* buildTree(vector<string> &nodes, int &index) {
        
        if (nodes[index] == "N") {  // null node
            index++;
            return nullptr;
        }

        // create node
        TreeNode* root = new TreeNode(stoi(nodes[index]));
        index++;

        root->left = buildTree(nodes, index);   // build left
        root->right = buildTree(nodes, index);  // build right

        return root;
    }

    TreeNode* deserialize(string data) {
        
        vector<string> nodes;
        string temp;

        // split string by commas
        for (char c : data) {
            if (c == ',') {
                nodes.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }

        int index = 0;
        return buildTree(nodes, index);
    }
};

