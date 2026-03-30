class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>st;
        vector<int>ans(temperatures.size());
        for(int i = temperatures.size() - 1; i >= 0; i--){
            pair<int,int>temp = {-1, -1};
            while(!st.empty()){
                if(st.top().first > temperatures[i]){
                    temp = st.top();
                    break;
                }
                st.pop();
            }
            ans[i] = temp.first != -1 ?temp.second - i  : 0;
            st.push({temperatures[i], i});
        }
        return ans;
    }
};
