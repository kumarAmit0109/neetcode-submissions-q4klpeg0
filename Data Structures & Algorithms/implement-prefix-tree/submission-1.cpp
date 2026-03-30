class TrieNode {
public:
    // Map that stores child nodes for each character
    // key   -> character
    // value -> pointer to the next TrieNode
    unordered_map<char, TrieNode*> children;
    // Flag to indicate whether a word ends at this node
    bool endOfWord = false;
};

class PrefixTree {
    // Root node of the Trie
    TrieNode* root;

public:
    // Constructor: initialize the root node
    PrefixTree() {
        root = new TrieNode();
    }

    void insert(string word) {

        // Start from the root
        TrieNode* cur = root;
        // Traverse every character of the word
        for (char c : word) {
            // If the character does not exist in the current node's children
            if (cur->children.find(c) == cur->children.end()) {
                // Create a new node for that character
                cur->children[c] = new TrieNode();
            }
            // Move to the next node
            cur = cur->children[c];
        }
        // After inserting all characters, mark the last node as end of a word
        cur->endOfWord = true;
    }

    bool search(string word) {
        // Start from root
        TrieNode* cur = root;
        // Traverse each character of the word
        for (char c : word) {
            // If the character path does not exist → word not found
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            // Move to the next node
            cur = cur->children[c];
        }
        // Word exists only if this node marks end of a word
        return cur->endOfWord;
    }

    bool startsWith(string prefix) {
        // Start from root
        TrieNode* cur = root;
        // Traverse the prefix
        for (char c : prefix) {
            // If the prefix path doesn't exist
            if (cur->children.find(c) == cur->children.end()) {
                return false;
            }
            // Move to the next node
            cur = cur->children[c];
        }
        // If traversal finished successfully → prefix exists
        return true;
    }
};