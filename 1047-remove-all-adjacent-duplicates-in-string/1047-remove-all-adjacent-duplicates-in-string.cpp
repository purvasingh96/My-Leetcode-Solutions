class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top() == s[i]) {
                while(!st.empty() && st.top() == s[i]){
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        
        int n = st.size();
        string res(n, 'a');
        int i=n-1;
        while(!st.empty()){
            res[i--] = st.top();
            st.pop();
        }
        
        return res;
    }
};