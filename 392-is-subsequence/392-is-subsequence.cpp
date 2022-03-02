class Solution {
public:
    bool isSubsequence(string s, string t) {
        stack<char> st;
        
        for(int i=s.length()-1;i>=0;i--) {
            
            st.push(s[i]);
            
        }
        
        for(int i=0;i<t.length();i++) {
            
            if(st.empty()) return true;
            
            if(t[i] == st.top()) {
                st.pop();
            }
            
        }
        
        return st.empty();
    }
};