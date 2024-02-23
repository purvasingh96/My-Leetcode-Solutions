class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        
        for(auto c:s){
            if(st.empty() || st.top()!=c){
                st.push(c);
            } else {
                st.pop();
            }
        }
        
        int n = st.size();
        string res(n, '#');
        int pos = n-1;
        
        while(!st.empty()){
            res[pos--] = st.top();
            st.pop();
        }
        
        return res;
    }
};