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

    // SERIALIZE: convert tree → string using level order (BFS)
    string serialize(TreeNode* root) {

        // if tree empty, return marker
        if(root == nullptr){
            return "N,";
        }

        string res;
        queue<TreeNode*> que;
        que.push(root);  // start from root

        while(!que.empty()){

            TreeNode* node = que.front();
            que.pop();

            // if null node, store N
            if(!node){
                res += "N,";
            }
            else{
                // store node value
                res += to_string(node->val) + ",";

                // push children (even if null)
                que.push(node->left);
                que.push(node->right);
            }
        }

        return res;
    }


    // DESERIALIZE: convert string → tree using level order
    TreeNode* deserialize(string data) {

        // if empty tree
        if(data == "N,"){
            return nullptr;
        }

        // split string by comma
        vector<string> nodes;
        string temp;

        for(char ch : data){
            if(ch == ','){
                nodes.push_back(temp);
                temp = "";
            }
            else{
                temp += ch;
            }
        }

        // create root from first value
        int i = 0;
        TreeNode* root = new TreeNode(stoi(nodes[i]));

        queue<TreeNode*> que;
        que.push(root);
        i++;

        // build tree level by level
        while(!que.empty()){

            TreeNode* curr = que.front();
            que.pop();

            // create left child if not N
            if(nodes[i] != "N"){
                curr->left = new TreeNode(stoi(nodes[i]));
                que.push(curr->left);
            }
            i++;

            // create right child if not N
            if(i < nodes.size() && nodes[i] != "N"){
                curr->right = new TreeNode(stoi(nodes[i]));
                que.push(curr->right);
            }
            i++;
        }

        return root;
    }
};
