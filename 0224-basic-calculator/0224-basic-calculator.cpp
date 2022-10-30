class Solution {
public:
    int calculate(string s) {
        stack<string> st;
        string temp = "";
        string t = "("+s+")";
        s = t;
        
        
        for(int i=0;i<s.length();i++){
            
            if(isdigit(s[i])){
                temp += s[i];
            }
            
            if(!isdigit(s[i]) && s[i]!=' '){
                // + or - or ()
                if(temp!="") {
                    if(st.top() == "-") {
                        st.pop();
                        int val = stoi(temp);
                        st.push(to_string(-val));
                    } else {
                        st.push(temp);
                    }
                    temp = "";
                }
                
                
                if(s[i] == '(') {
                    st.push("(");
                }
                
                else if(s[i] == ')') {
                    int res=0;
                    while(st.top()!="("){
                        res += stoi(st.top());
                        st.pop();
                    }
                    st.pop();
                    
                    if(!st.empty() && st.top() == "-"){
                        st.pop();
                        
                        st.push(to_string(-res));
                    } else {
                        st.push(to_string(res));
                    }
                    
                } 
                
                else if(s[i] == '-') st.push("-");
                
               
                
            }
            
        }
        
        return stoi(st.top());
    }
};