class MinStack {
public:
    
    multiset<int> m;
    stack<int> st;
    MinStack() {
       
    }
    
    void push(int val) {
        st.push(val);
        m.insert(val);
    }
    
    void pop() {
        m.erase ( m.find(st.top()) );
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return *m.begin();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */