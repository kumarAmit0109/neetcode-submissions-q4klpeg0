class TrieNode {
public:
    vector<TrieNode*> children;
    bool isTerminal;
    // constructor
    TrieNode() : children(26, nullptr), isTerminal(false) {}
};

class WordDictionary {
public:
    TrieNode* root;
    // create root node
    WordDictionary() {
        root = new TrieNode();
    }
    void addWord(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            // create node if it does not exist
            if (curr->children[ch - 'a'] == nullptr) {
                curr->children[ch - 'a'] = new TrieNode();
            }
            // move to next node
            curr = curr->children[ch - 'a'];
        }
        // mark end of word
        curr->isTerminal = true;
    }

    bool dfs(string word, int j, TrieNode* node) {
        TrieNode* curr = node;

        for (int i = j; i < word.size(); i++) {
            char ch = word[i];
            // wildcard case
            if (ch == '.') {
                // try every possible child
                for (TrieNode* child : curr->children) {
                    if (child != nullptr && dfs(word, i + 1, child)) {
                        return true;
                    }
                }
                return false;
            }
            // normal character case
            if (curr->children[ch - 'a'] == nullptr) {
                return false;
            }
            curr = curr->children[ch - 'a'];
        }
        // check if we reached end of a valid word
        return curr->isTerminal;
    }

    bool search(string word) {
        // strt with the indx zero
        return dfs(word, 0, root);
    }
};