class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp="";
        stack<string> st;
        
        int i=0;
        while(i<s.length()){
            while(i<s.length() && s[i]!=' '){
                string t(1, s[i]);
                temp += t;
                i+=1;
            }
            if(temp!=""){
                st.push(temp);
                temp="";
            }
            i+=1;
        }
        
        string res="";
        while(!st.empty()){
            res+=st.top();
            res+=" ";
            st.pop();
        }
        
        res.pop_back();
        return res;
    }
};