class TrieNode {
public:
    unordered_map<char, TrieNode*>children;
    bool isWord;

    TrieNode() : isWord(false){

    }

    void addWord(const string& word){
        TrieNode* curr = this;
        for(char ch : word){
            if(!curr->children.count(ch)){
                curr->children[ch] = new TrieNode();
            }
            curr = curr->children[ch];
        }
        curr->isWord = true;
    }
};

class Solution {
public:
    unordered_set<string>res;

    void solve(vector<vector<char>>& board, int r, int c, TrieNode* node, string& word, vector<vector<bool>>& visited){
        int rows = board.size();
        int cols = board[0].size();
        // check whether the we got out of bound or not , also 
        // if the children of node in trie contain the board[r][c] or not
        // in those cases simply return do nothing
        if((r < 0 || r >= rows) || 
           (c < 0 || c >= cols) || 
           visited[r][c] || 
           (node->children.count(board[r][c]) == 0)){ 
            return;
        }

        // mark visited current board[r][c] postion in visited map
        visited[r][c] = true;
        // update the node
        node = node->children[board[r][c]];
        
        word += board[r][c];
        if(node->isWord){
            res.insert(word);
            // node->isWord = false; // optional optimization
        }
        
        // make recursive call in each direction
        vector<pair<int,int>>directions{{1,0}, {-1,0}, {0,1}, {0,-1}};
        for(auto dir : directions){
            int newr = r + dir.first;
            int newc = c + dir.second;
            solve(board, newr, newc, node, word, visited);
           
        }

        // backtracking
        word.pop_back();   
        visited[r][c] = false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int rows = board.size();
        int cols = board[0].size();
        
        TrieNode* root = new TrieNode();
        // add all the words in trie
        for(const string& word : words){
            root->addWord(word);
        }

        // create a visited map to track whether the curr char is visited or not
        vector<vector<bool>>visited(rows, vector<bool>(cols, false));

        // now for every char in board make the call to find the whole trie
        // nd for any reached node if its isWord is true means we found a word
        // on the board simply store it
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                // strt with the initially empty word
                string word = ""; 
                solve(board, r, c, root, word, visited);
            }
        }
        return vector<string>(res.begin(), res.end());
    }
};