class Solution {
public:
    string countAndSay(int n) {
        cout<<"n: "<<n<<"\n";
        if(n == 1){
            return "1";
        }
        
        string t = countAndSay(n-1);
        //cout<<"t:: "<<t<<"\n";

        string res="";
        stack<char> st;
        
        for(int i=0;i<t.length();i++){
            if(st.empty() || t[i] == st.top()){
                st.push(t[i]);
            } else {
                res += st.size() + '0';
                res += st.top();
                while(!st.empty()){
                    st.pop();
                }
                st.push(t[i]);
            }
        }
        if(!st.empty()){
            res += st.size() + '0';
            res += st.top();
        }
        return res;
    }
};