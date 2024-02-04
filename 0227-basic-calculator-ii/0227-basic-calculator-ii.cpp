class Solution {
private:
    bool isdigit(char c){
        return c>='0' && c<='9';
    }
public:
    int calculate(string s) {
        stack<int> st;
        char sign = '+';
        
        // O(N);
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                continue;
            } else {
                if(isdigit(s[i])){
                    int d=0;
                    while(i<s.length() && isdigit(s[i])){
                        d = d*10 + (s[i]-'0');
                        i+=1;
                    }
                    if(sign == '+'){
                        st.push(d);
                    } else if(sign == '-'){
                        st.push(-1*d);
                    } else if(sign == '/'){
                        int top = st.top();
                        st.pop();
                        st.push(top/d);
                    } else if(sign == '*'){
                        int top = st.top();
                        st.pop();
                        st.push(top*d);
                    }
                    i-=1;
                } else {
                    sign = s[i];
                }
            }
        }
        
        // O(L)
        int ans=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans += top;
        }
        
        // O(N+L), O(L)
        
        return ans;
    }
};