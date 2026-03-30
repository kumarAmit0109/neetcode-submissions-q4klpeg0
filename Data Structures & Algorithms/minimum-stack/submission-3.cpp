class MinStack {
public:
    stack<long long> st;   // use long long
    long long currentMin;

    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push(0);
            currentMin = val;
        } else {
            st.push((long long)val - currentMin);
            if (val < currentMin) {
                currentMin = val;
            }
        }
    }

    void pop() {
        if (st.empty()) return;

        long long diff = st.top();
        st.pop();

        if (diff < 0) {
            currentMin = currentMin - diff;
        }
    }

    int top() {
        long long diff = st.top();
        if (diff > 0) {
            return (int)(currentMin + diff);
        } else {
            return (int)currentMin;
        }
    }

    int getMin() {
        return (int)currentMin;
    }
};
