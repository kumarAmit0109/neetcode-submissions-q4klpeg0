class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()){
            return false;
        }
        vector<int>count1(26, 0);
        vector<int>count2(26, 0);
        
        for(int i = 0; i < s1.length(); i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }

        int matches = 0;
        for(int i = 0; i < 26; i++){
            if(count1[i] == count2[i]){
                matches++;
            }
        }
        
        int left = 0;
        for(int right = s1.length(); right < s2.length(); right++){
            if(matches == 26 ){
                return true;
            }

            int indx = s2[right] - 'a';
            count2[indx]++;
            if(count1[indx] == count2[indx]){
                matches++;
            }else if(count1[indx] +1 == count2[indx]){
                matches--;
            }

            indx = s2[left] - 'a';
            count2[indx]--;
            if(count1[indx] == count2[indx]){
                matches++;
            }else if(count1[indx] - 1 == count2[indx]){
                matches--;
            }
            left++;
        }

        return matches == 26;
    }
};
