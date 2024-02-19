class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) {
            return "1";
        }
        
        string t = countAndSay(n-1);
        string res ="";
        
        stack<char> st;
        for(int i=0;i<t.length();i++){
            if(st.empty() || t[i] == st.top()){
                st.push(t[i]);
            } else {
                char c = st.size() + '0';
                char top = st.top();
                res += c;
                res += top;
                while(!st.empty()){
                    st.pop();
                }
                st.push(t[i]);
            }
        }
        
        if(!st.empty()){
            char c = st.size() + '0';
            char top = st.top();
            res += c;
            res += top;
        }
        return res;
    }
};