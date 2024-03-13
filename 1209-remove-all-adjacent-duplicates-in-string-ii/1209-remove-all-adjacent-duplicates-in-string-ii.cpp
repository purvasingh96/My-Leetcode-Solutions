class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        for(int i=0;i<s.length();i++){
            if(st.empty() || st.top().first != s[i]){
                st.push({s[i], 1});
            } else {
                int count = st.top().second+1;
                st.pop();
                if(count!=k){
                    st.push({s[i], count});    
                } 
            }
        }
        
        string res="";
        while(!st.empty()){
            auto f = st.top();
            st.pop();
            string c(f.second, f.first);
            res+=c;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};