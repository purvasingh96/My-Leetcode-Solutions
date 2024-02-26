class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        int d=0;
        
        for(auto x:s){    
            if(x == ' '){
                continue;
            }
            if(isdigit(x)){
                d = d*10 + (x-'0');
            } else {
                if(op == '+'){
                    st.push(d);
                } else if(op == '-'){
                    st.push(-1*d);
                } else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * d);
                } else if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / d);    
                }
                d=0;
                op = x;
            }    
        }
        
        if(op == '+'){
                    st.push(d);
                } else if(op == '-'){
                    st.push(-1*d);
                } else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * d);
                } else if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top / d);    
                }
        int ans=0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};