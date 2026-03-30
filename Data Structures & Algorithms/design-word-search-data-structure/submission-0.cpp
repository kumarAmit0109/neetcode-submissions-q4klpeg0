class WordDictionary {
public:
    vector<string> store;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        // for adding the word simply push it in the store vector
        store.push_back(word);
    }
    
    bool search(string word) {
        // for searching simply compare the every string in the store 
        // with the word string
        for(string str : store){
            // if length are differnt then simply continue to check with other
            if(str.length() != word.length()){
                continue;
            }

            int i = 0;
            while(i < str.length()){
                // '.' can be match with any character so simply i++ in that
                // case also
                if(str[i] == word[i] || word[i] == '.'){
                    i++;
                }else{
                    break;
                }
            }

            // if all the characters match then return true
            if(i == str.length()){
                return true;
            }

        }
        return false;        
    }
};
