class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freqInS(26,0);
        vector<int>freqInT(26,0);
        for(char ch : s){
            int indx = ch-'a';
            freqInS[indx]++;
        }
         for(char ch : t){
            int indx = ch-'a';
            freqInT[indx]++;
        }

        for(int i = 0; i < 26; i++){
            if(!(freqInS[i] == freqInT[i])){
                return false;
            }
        }
        return true;
    }
};
