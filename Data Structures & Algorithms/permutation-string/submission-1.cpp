class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char, int> count1;
       for(char ch : s1){
        count1[ch]++;
       }

       int need = count1.size();
       for(int i = 0; i < s2.length(); i++){
        unordered_map<char, int>count2;
        int curr = 0;
        for(int j = i; j < s2.length(); j++){
            count2[s2[j]]++;

            if(count1[s2[j]] < count2[s2[j]]){
                break;
            }
            if(count1[s2[j]] == count2[s2[j]]){
                curr++;
            }
            if(curr == need){
                return true;
            }
        }

       }
       return false;
    }
};
