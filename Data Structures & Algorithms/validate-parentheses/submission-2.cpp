class Solution {
public:
    bool isValid(string s) {
        stack<char>st;

        for(char ch : s){
            if(ch == '(' || ch == '[' || ch == '{'){
                st.push(ch);
            }else{
                if(st.empty()){
                    return false;
                }else{
                    char temp = st.top();
                    if((temp == '{' && ch == '}') || (temp == '(' && ch == ')') ||
                        (temp == '[' && ch == ']')){
                            st.pop();
                        }else{
                            return false;
                        }
                }
            }
        }
        return st.empty();
        
    }
};
