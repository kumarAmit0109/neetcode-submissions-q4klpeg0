class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // use unordered set for fast lookup
        unordered_set<string>words(wordList.begin(), wordList.end());
        // check if endword is not empty or it still exist in the wordlist
        // if not simply return 0
        if (endWord.empty() || find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        int cnt = 1;
        queue<string>que;
        que.push(beginWord);

        while(!que.empty()){
            int len = que.size();
            for(int i = 0; i < len; i++){
                string node = que.front();
                que.pop();
                
                // if we reach the target node simply return cnt
                if(node == endWord){
                    return cnt;
                }

                // now for each char in node word, replace it with every char
                // from a to z except original one, then check if we find it in
                // the set if yes push the word in que nd delete the entry from set
                // so we didn't visit it again 
                for(int j = 0; j < node.length(); j++){
                    char temp = node[j];
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        // if ch is equal to temp continue
                        if(ch == temp){
                            continue;
                        }
                        node[j] = ch;
                        if(words.find(node) != words.end()){
                            que.push(node);
                            words.erase(node);
                        }
                    }
                    // replace the original node
                    node[j] = temp;
                }
            }
            // increment cnt after finishing one level
            cnt++;
        }
        // if no transformation found return 0
        return 0;
    }
};
