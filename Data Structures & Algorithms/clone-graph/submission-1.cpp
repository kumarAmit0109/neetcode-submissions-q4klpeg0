/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // if node doesn't exist simply return null
        if(!node){
            return nullptr;
        }

        // create unordered_map to keep track of whether the node is already
        // clonned or not
        unordered_map<Node*, Node*> oldToNew;
        queue<Node*>que;

        // create root node copy nd push it into que in order to start
        // the bfs traversal
        oldToNew[node] = new Node(node->val);
        que.push(node);

        while(!que.empty()){
            Node* curr = que.front();
            que.pop();
            
            // process the neighbour nodes
            for(Node* neigh : curr->neighbors){
                // if the mapping doesnot found then crate the mapping
                // nd push it into que
                if(oldToNew.find(neigh) == oldToNew.end()){
                    oldToNew[neigh] = new Node(neigh->val);
                    que.push(neigh);
                }
                // if mapping exists simply copy the neighbours nodes 
                // in the curr node's neightbour
                oldToNew[curr]->neighbors.push_back(oldToNew[neigh]);

            }
        }
        // return copied root node
        return oldToNew[node];
    }
};
