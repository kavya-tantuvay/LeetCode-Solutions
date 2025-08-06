class MinStack {
public:
    long long mini;
    stack<long long>st;
    MinStack() {
        mini=INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            mini=val;
            st.push(val);
        }
        else{
            if(val<mini){
                st.push(2LL*val-mini);
                mini=val;
            }
            else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty())return;
        else{
           long long t=st.top();
           st.pop();
           if(t<mini)mini=2LL*mini-t;
        }
        
    }
    
    int top() {
        if(st.empty())return -1;
        else{
            if(st.top()<mini){
                return mini;
            }
            else{
                return st.top();
            }
        }
    }
    
    int getMin() {
        return mini;
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