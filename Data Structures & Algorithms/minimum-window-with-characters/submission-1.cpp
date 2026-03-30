class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()){
            return " ";
        }
        unordered_map<char, int>freqT, window;
        for(char ch : t){
            freqT[ch]++;
        }

        int have = 0, need = freqT.size();
        pair<int,int>res = {-1, -1};
        int resLen = INT_MAX;
        int left = 0;

        for(int right = 0; right < s.length(); right++){
            char ch = s[right];
            window[ch]++;

            if(freqT.count(ch) && window[ch] == freqT[ch]){
                have++;
            }

            while(have == need){
                if((right - left + 1) < resLen){
                    resLen = right - left + 1;
                    res = {left, right};
                }

                window[s[left]]--;
                if(freqT.count(s[left]) && window[s[left]] < freqT[s[left]]){
                    have--;
                }
                left++;
            }
        }
        
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
