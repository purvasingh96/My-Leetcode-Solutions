class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        char op = '+';
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                continue;
            } else {
                if(isdigit(s[i])){
                    int d=0;
                    while(i<s.length() && isdigit(s[i])){
                        d = d*10 + (s[i]-'0');
                        i+=1;
                    }
                    
                    i-=1;
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
                } else {
                    op = s[i];
                }
                
                
            }
        }
        
        int ans=0;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};