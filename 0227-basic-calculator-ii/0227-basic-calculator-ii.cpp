class Solution {
public:
    int calculate(string s) {
        
        stack<int> st;
        bool minus=false;
        int num=0;
        char op = '+';
        
        for(int i=0;i<s.length();i++){
            char currChar = s[i];
            if(isdigit(currChar)){
                num = num*10 + (currChar - '0');
            }
            
            if(!isdigit(currChar) && currChar!=' ' || i==s.length()-1){
                if(op == '+'){
                    st.push(num);
                } else if(op == '-'){
                    st.push(-num);
                } else if(op == '*'){
                    int x = st.top();
                    st.pop();
                    st.push(x*num);
                } else if(op == '/'){
                    int x = st.top();
                    st.pop();
                    st.push(x/num);
                }
                op = currChar;
                num=0;
            }
            
        }
        
        int res=0;
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        
        return res;
        
    }
};