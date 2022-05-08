class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> st;
        int i=0;
        
        while(i<s.length()) {
            
            if(st.empty() || st.top()!=s[i]) {
                st.push(s[i]);
                i+=1;
            } else{
                
                while(s[i] == st.top()) {
                    st.push(s[i]);
                    i+=1;
                }
                
                int tk = 0;
                int toprep = st.top();
                
                while(!st.empty() && st.top()==toprep) {
                    
                    st.pop();
                    tk+=1;
                    
                }
                
                if(tk%k!=0) {
                    
                    int rem = (tk%k);
                    
                    while(rem!=0) {
                        
                        st.push(toprep);
                        rem -= 1;
                        
                    }
                    
                }
                
                
            }
            
            
        }
        
        string res(st.size(), '@');
        //res.reserve
        int j = st.size()-1;
        
        while(!st.empty()) {
            res[j--] = st.top();
            st.pop();
        }
        
        //reverse(res.begin(), res.end());
        return res;
        
        
    }
};