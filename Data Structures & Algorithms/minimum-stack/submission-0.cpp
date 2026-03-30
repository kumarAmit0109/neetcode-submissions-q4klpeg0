class MinStack {
public:
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>tmp;
        int mini = st.top();

        while(!st.empty()){
            mini = min(mini, st.top());
            tmp.push(st.top());
            st.pop();
        }

        while(!tmp.empty()){
            st.push(tmp.top());
            tmp.pop();
        }

        return mini;
    }
};
