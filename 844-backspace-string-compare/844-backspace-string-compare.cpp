class Solution {
public:
    void finalString(string s, stack<char>& st) {
        for(auto x:s) {
            
            if(x!='#') {
                st.push(x);
            }
            
            else if(x=='#') {
                if(st.empty()) continue;
                else st.pop();
            }
            
        }
    }
    
    bool backspaceCompare(string s, string t) {
        stack<char> sts;
        stack<char> stt;
        
        finalString(s, sts);
        finalString(t, stt);
        
        if(sts.size()!=stt.size()) {
            return false;
        }
        
        while(!sts.empty()) {
            if(sts.top()!=stt.top()) return false;
            sts.pop();
            stt.pop();
        }
        
        return true;
    }
};