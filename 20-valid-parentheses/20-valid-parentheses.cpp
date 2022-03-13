class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        
        for(int i=1;i<s.length();i++) {
            if(!st.empty()) {
                if(s[i] == '}' && st.top() == '{') st.pop();
                else if(s[i] == ')' && st.top() == '(')st.pop();
                else if(s[i] == ']' && st.top() == '[') st.pop();
                else st.push(s[i]);
            }
            
            else st.push(s[i]);
            
        }
        
        return st.empty();
        
        
    }
};