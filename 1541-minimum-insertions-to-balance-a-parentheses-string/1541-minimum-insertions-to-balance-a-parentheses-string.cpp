class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n=s.length();
        int c=0;
        
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                st.push(s[i]);
            } else {
                // s[i] = ')'
                if(st.empty()){
                    if(i+1<n && s.substr(i, 2) == "))"){
                        c+=1;
                        i+=1;
                    } else {
                        c+=2;
                    }
                } else {
                    if(i+1<n && s.substr(i, 2) == "))"){
                        i+=1;
                        st.pop();
                    } else {
                        st.pop();
                        c+=1;
                    }
                }
            }
        }
        
        return c + st.size()*2;
    }
};