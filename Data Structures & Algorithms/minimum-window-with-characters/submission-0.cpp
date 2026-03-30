class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()){
            return " ";
        }
        unordered_map<char, int>freqT;
        for(char ch : t){
            freqT[ch]++;
        }

        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        for(int i = 0; i < s.length(); i++){
            unordered_map<char, int> freqS;
            for(int j = i; j < s.length(); j++){
                freqS[s[j]]++;

                bool flag = true;
                for(auto i : freqT){
                    if(freqS[i.first] < i.second){
                        flag = false;
                        break;
                    }
                }

                if(flag && (j - i + 1) < resLen){
                    resLen = j - i + 1;
                    res = {i , j};
                }
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
