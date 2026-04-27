class Solution {
public:
    int dfs(int i, int j, string& word1, string& word2, int m, int n){
        // if i reach the end of word1, means that there still char left
        // in word2, so we need to add remaining char in word1 so return
        // n - j
        if(i == m){
            return n - j;
        }

        // if j reach the end of word2, means that the word2 exhausted but there
        // is still char left in word1, so we need to delete those chars so return
        // m - i
        if(j == n){
            return m - i;
        }

        // if we char in both word1 and word2 are same then do nothing,
        // simply increase both pointers and make nxt recursive call
        if(word1[i] == word2[j]){
            return dfs(i+1, j+1, word1, word2, m, n);
        }

        // in other cases make 3 choice, delete, insert, replace
        int del = dfs(i+1, j, word1, word2, m, n);
        int insrt = dfs(i, j+1, word1, word2, m, n);
        int repl = dfs(i+1, j+1, word1, word2, m, n);

        int res = min(del, insrt);
        return  1 + min(res, repl); // +1 for curr operation used
    }
    int minDistance(string word1, string word2) {
        // strt recursive call with 0th index for both word1 and word2,
        // also pass the sizes of word1 and word2
        int m = word1.size();
        int n = word2.size();
        int res = dfs(0, 0, word1, word2, m, n);
        return res;
    }
};
