class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> st;
        
        int i=0;
        
        while(i<s.length()) {
            
            if(st.empty() || s[i]!=st.back().first)  {
                st.push_back(make_pair(s[i], 1));
                i+=1;
            } else{
                
                auto curr = st.back();
                
                if(curr.second+1 == k) {
                    st.pop_back();
                } else{
                    st.pop_back();
                    st.push_back(make_pair(curr.first, curr.second+1));
                    
                    
                }
                    
                i+=1;
                
            }
            
        }
        
        string res="";
        
        for(auto x:st) {
            res += string(x.second, x.first);
        }
        return res;
        
        
    }

    
};