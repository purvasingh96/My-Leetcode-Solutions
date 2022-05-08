class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        
        int i=0;
        
        while(i<s.length()) {
            
            if(st.empty() || s[i]!=st.top().first)  {
                st.push(make_pair(s[i], 1));
                i+=1;
            } else{
                
                auto curr = st.top();
                
                if(curr.second+1 == k) {
                    st.pop();
                } else{
                    st.pop();
                    st.push(make_pair(curr.first, curr.second+1));
                    
                    
                }
                    
                i+=1;
                
            }
            
        }
        
        string res="";
        
        while(!st.empty()) {
            
            auto curr = st.top();
            st.pop();
            int f = curr.second;
            
            while(f!=0) {
                res+= (curr.first);
                f-=1;
            }
            
            
        }
        
        reverse(res.begin(), res.end());
        return res;
        
        
    }
};