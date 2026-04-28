class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, unordered_set<char>>adj;
        unordered_map<char, int>indegree;

        // initialize every character with empty adj list and indegree 0
        // ensures even chars with no edges have an entry
        for(string word : words){
            for(char ch : word){
                adj[ch] = unordered_set<char>();
                indegree[ch] = 0;
            }
        }

        // create adjacency list and also initialise the indegree for every node
        for(int i = 0; i < words.size()-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int minLen = min(word1.size(), word2.size());

            // edge case where the earlier word is of longer length than later word and
            // contains the later words as the prefix so, in that case there is not valid
            // alein alphabet possible so return ""
            // example: ["apple", "app"] → invalid, longer word can't come before its prefix
            if(word1.size() > word2.size() && word1.substr(0, minLen) == word2.substr(0, minLen)){
                return "";
            }

            for(int j = 0; j < minLen; j++){
                // if the characters are not equal and their entry doesn't exist
                // in the adj so create one and increase the indegree;
                // only first differing character gives the ordering rule
                // rest of the characters tell us nothing about order
                if(word1[j] != word2[j]){
                    // avoid duplicate edges
                    if(!adj[word1[j]].count(word2[j])){
                        adj[word1[j]].insert(word2[j]);
                        indegree[word2[j]]++;
                    }
                    // only first difference matters
                    break;
                }
            }
        }

        // apply kahn's algorithm to find the topological sort as 
        // the char appear in our topological sort indicates the alien alphabet
        queue<char>que;
        for(auto &[ch, deg] : indegree){
            if(deg == 0){
                que.push(ch);
            }
        }
        string res = "";
        while(!que.empty()){
            char ch = que.front();
            que.pop();
            res += ch;
            for(char nei : adj[ch]){
                indegree[nei]--;
                if(indegree[nei] == 0){
                    que.push(nei);
                }
            }
        }

        // if at the end the size of res is equal to the indegree size 
        // indicates it an valid topological sort so there is no cycle nd
        // we can get the valid aphabetic order so return res in that case
        return res.size() == indegree.size() ? res : "";
    }
};
