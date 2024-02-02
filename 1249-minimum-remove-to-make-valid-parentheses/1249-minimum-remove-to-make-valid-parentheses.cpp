class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        string res = "";
        vector<int> idx;
        
        for(int i=0;i<s.length();i++){
                char c = s[i];
                if(c == '('){
                    st.push({'(', i});
                } else if(c== ')') {
                    if(st.empty()){
                        idx.push_back(i);
                    } else {
                        st.pop();
                    } 
                }
            
        }
        
        while(!st.empty()){
            auto c = st.top();
            st.pop();
            idx.push_back(c.second);
        }
        
        sort(idx.begin(), idx.end());
        int j=0;
        
        for(int i=0;i<s.length();i++){
            if(j>=idx.size()){
                res += s[i];
            } else {
               if(i!=idx[j]){
                 res += s[i];
                } else {
                    j+=1;
                } 
            }
            
        }
        
        return res;
    }
};