class Solution {
public:
    int calculate(string s) {
        char op = '+';
        stack<long> st;
        
        long d=0;
        
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                continue;
            }
            if(isdigit(s[i])){
                d=d*10 + s[i]-'0';
            } else {
                if(op == '+'){
                    st.push(d);
                } else if(op == '-'){
                    st.push(-d);
                } else if(op == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(top * d);
                } else if(op == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/d);
                }
                op = s[i];
                d=0;
            }
        }
        
        if(op == '+'){
            st.push(d);
        } else if(op == '-'){
            st.push(-d);
        } else if(op == '*'){
           int top = st.top();
            st.pop();
            st.push(top * d);
        } else if(op == '/'){
            int top = st.top();
            st.pop();
            st.push(top/d);
        }
        
        int ans=0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        return ans;
        
    }
};