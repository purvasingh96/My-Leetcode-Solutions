class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int cur_num = 0;
        char op = '+';
        
        
        for(int i=0;i<s.length();i++) {
            
            char current_char = s[i];
            
            if(isdigit(current_char)) {
                
                cur_num = (cur_num*10) + (s[i] - '0');
                
            } 
            
            if(!isdigit(current_char) && current_char!=' ' || i == s.length()-1) {
                
                if(op == '-') st.push(-cur_num);
                
                else if(op == '+') st.push(cur_num);
                
                else if(op == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top*cur_num);
                    
                } else if(op == '/') {
                    int top = st.top();
                    st.pop();
                    st.push(top / cur_num);
                }
                
                
            op = current_char;
            cur_num = 0;
                
            }
            
            
        }
        
        int res = 0;
        
        while(st.size()!=0) {
            res+=st.top();
            st.pop();
        }
        
        return res;
        
    }
};