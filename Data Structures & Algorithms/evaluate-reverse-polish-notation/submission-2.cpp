class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        for(const string & ch : tokens){
            if(ch == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            }else if(ch == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }else if(ch == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }else if(ch == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }else{
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};
