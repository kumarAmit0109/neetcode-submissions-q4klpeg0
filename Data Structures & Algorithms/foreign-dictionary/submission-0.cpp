class Solution {
public:
    bool dfs(char ch, map<char, vector<char>>& adj, map<char, bool>& visited, string& result) {
        // already processed this node before
        if(visited.find(ch) != visited.end()){
            return visited[ch];  // if true means cycle detected
        }

        visited[ch] = true;  // mark as currently visiting

        for(char neighbor : adj[ch]){
            if(dfs(neighbor, adj, visited, result)){
                return true;  // cycle found, bubble up
            }
        }

        visited[ch] = false;      // safely done with this node
        result.push_back(ch);     // add to result after all dependencies
        return false;
    }

    string foreignDictionary(vector<string>& words) {
        map<char, vector<char>> adj;
        map<char, bool> visited;
        string result;

        // Step 1: initialize every character in adj
        // so even chars with no edges have an entry
        for(const string& word : words){
            for(char ch : word){
                adj[ch];
            }
        }

        // Step 2: compare adjacent words to find ordering rules
        for(int i = 0; i < words.size() - 1; i++){
            string w1 = words[i];
            string w2 = words[i + 1];
            int minLen = min(w1.length(), w2.length());

            // edge case : "apple" before "app" is impossible
            if(w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)){
                return "";
            }

            // find first different character between w1 and w2
            // that character gives us an ordering rule
            for(int j = 0; j < minLen; j++){
                if(w1[j] != w2[j]){
                    adj[w1[j]].push_back(w2[j]);  // w1[j] comes before w2[j]
                    break;  // only first difference matters, rest are unknown
                }
            }
        }

        // Step 3: run dfs on every character
        // to get topological order + detect cycles
        for(const auto& pair : adj){
            if(dfs(pair.first, adj, visited, result)){
                return "";  // cycle means invalid ordering
            }
        }

        // dfs adds in reverse order so flip it
        reverse(result.begin(), result.end());
        return result;
    }
};