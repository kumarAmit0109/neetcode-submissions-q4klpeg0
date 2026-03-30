class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>freqMap;

        for(string str : strs){
            vector<int>freqCount(26);
            for(char ch : str){
                freqCount[ch - 'a']++;
            }

            string key = to_string(freqCount[0]);
            for(int i = 0; i < 26; i++){
                key += ','+to_string(freqCount[i]);
            }
            freqMap[key].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(auto temp : freqMap){
            ans.push_back(temp.second);
        }
        return ans;
    }
};
