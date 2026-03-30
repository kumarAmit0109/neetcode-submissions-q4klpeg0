class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<int>st;
    //  using lambda function
       unordered_map<string, function<int (int,int)>> mp = {
        {"+" , [](int a, int b){return b + a;}},
        {"-" , [](int a, int b){return b - a;}},
        {"*" , [](int a, int b){return (long)b * (long)a;}},
        {"/" , [](int a, int b){return b / a;}},
       };


        for(const string& s : tokens){
            if( s == "+" || s == "-" || s == "*" || s == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                int result = mp[s](a , b);
                st.push(result);
            }else{
                st.push(stoi(s));
            }
        }
        return st.top();

    }
};
