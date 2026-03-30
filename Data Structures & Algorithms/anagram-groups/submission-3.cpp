class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>>freqMap;

        for(string str : strs){
            vector<int>freqCount(26);
            for(char ch : str){
                freqCount[ch - 'a']++;
            }
            freqMap[freqCount].push_back(str);
        }
        
        vector<vector<string>>ans;
        for(auto temp : freqMap){
            ans.push_back(temp.second);
        }
        return ans;
    }
};
