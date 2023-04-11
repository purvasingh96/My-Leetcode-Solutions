class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(auto c:s){
            if(c!='*'){
                st.push(c);
            } else {
                st.pop();
            }
        }
        int n = st.size();
        string ans(n, '#');
        int i=n-1;
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        
        return ans;
    }
};