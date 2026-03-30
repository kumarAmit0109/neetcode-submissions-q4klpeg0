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
    Node* dfs(Node* node, map<Node*, Node*>& oldToNew){
        if(node == nullptr){
            return nullptr;
        }

        // if node already exist in map means we already created its copy
        // so just return that copy to avoid duplicate creation and infinite loop
        if(oldToNew.count(node)){
            return oldToNew[node];
        }

        // else create a new copy nd store it in map and now call for all
        // its neighbours
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        for(Node* neigh : node->neighbors){
            // recursively clone each neighbor
            Node* copyNeighbor = dfs(neigh, oldToNew);
            // connect the cloned neighbor to current cloned node
            copy->neighbors.push_back(copyNeighbor);
        }
        return copy;

    }
    Node* cloneGraph(Node* node) {
        // use map to keep track of avoiding creation of duplicate node
        // and also prevent infinite recursion in cyclic graphs
        map<Node*, Node*>oldToNew;
        return dfs(node, oldToNew);
    }
};
