class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int, char>> st;
        
        for(int i=0;i<s.length();i++) {
            
            if(s[i] == '(') {
                
                st.push(make_pair(i, '('));
                
            } else if(s[i] == ')') {
                
               if(st.empty()) {
                   
                   st.push(make_pair(i, ')'));
                   
               } else {
                   
                   auto top = st.top();
                   
                   if(top.second == ')') {
                       
                       st.push(make_pair(i, ')'));
                       
                   } else {
                       
                       st.pop();
                       
                   }
                   
               }
                
            }
            
        }
        
        string ans = "";
        
        if(!st.empty()) {
            
            while(!st.empty()) {
                
                auto pos = st.top();
                st.pop();
                
                s[pos.first] = '#';
                
            }
            
        }
        
        s.erase(remove(s.begin(), s.end(), '#'), s.end());
        
        return s;
        
    }
};