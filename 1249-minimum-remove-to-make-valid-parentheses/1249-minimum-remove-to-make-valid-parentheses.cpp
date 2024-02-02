class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<char, int>> st;
        string res = "";
        set<int> idx;
        
        for(int i=0;i<s.length();i++){
                char c = s[i];
                if(c == '('){
                    st.push({'(', i});
                } else if(c== ')') {
                    if(st.empty()){
                        idx.insert(i);
                    } else {
                        st.pop();
                    } 
                }
            
        }
        
        while(!st.empty()){
            auto c = st.top();
            st.pop();
            idx.insert(c.second);
        }
        
       
        auto it = idx.begin();
        
        for(int i=0;i<s.length();i++){
            if(it==idx.end()){
                res += s[i];
            } else {
               if(i!=*it){
                 res += s[i];
                } else {
                    it++;
                } 
            }
            
        }
        
        return res;
    }
};