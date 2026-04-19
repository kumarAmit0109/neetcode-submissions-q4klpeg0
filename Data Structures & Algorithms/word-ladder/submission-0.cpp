class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // check if endword is not empty or it still exist in the wordlist
        // if not simply return 0
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        // now push the beginword in the word list and prepare pattern map
        // which determine the lists of word which follow same patterns or
        // having only one char difference
        unordered_map<string, vector<string>> neigh;
        wordList.push_back(beginWord);
        for (const string& word : wordList) {
            // replace char one by one nd make entry in map
            for (int j = 0; j < word.size(); j++) {
                string pattern = word.substr(0, j) + "*" + word.substr(j + 1, word.size());
                neigh[pattern].push_back(word);
            }
        }

        // prepare things for bfs traversal
        unordered_set<string> visit;
        queue<string> que;
        que.push(beginWord);
        visit.insert(beginWord);

        int cnt = 1;
        while (!que.empty()) {
            int size = que.size();
            // number of words at current level (same transformation distance)

            for (int i = 0; i < size; i++) {
                string word = que.front();
                que.pop();
                
                // if we reached target word → shortest path found
                if (word == endWord) {
                    return cnt;
                }
                // take one word from current BFS level
                // try changing each character of current word
                for (int j = 0; j < word.size(); j++) {
                    // create pattern like h*t, *ot, ho*
                    string pattern = word.substr(0, j) + "*" + word.substr(j + 1);

                    // get all words matching this pattern (1-letter difference)
                    for (const string neigWord : neigh[pattern]) {
                        // if not visited, process it
                        if (visit.find(neigWord) == visit.end()) {
                            visit.insert(neigWord);  // mark visited
                            que.push(neigWord);      // push into next BFS level
                        }
                    }
                }
            }

            // after finishing current level → move to next transformation step
            cnt++;
        }
        // if endword still not found return 0
        return 0;
    }
};
