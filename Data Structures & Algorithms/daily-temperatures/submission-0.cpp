class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans;
        
        for(int i = 0; i < temperatures.size(); i++){
            int cnt = 0;
            bool flag = false;
            for(int j = i; j < temperatures.size(); j++){
                if(temperatures[j]> temperatures[i]){
                    flag = true;
                    break;
                }
                cnt++;
            }
            ans.push_back( flag ? cnt : 0 );
        }
        return ans;
    }
};
