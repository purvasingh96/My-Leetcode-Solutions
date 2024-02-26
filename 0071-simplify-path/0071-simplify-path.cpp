class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;
        
        while(getline(ss, token, '/')){
            if(token == "."){
                continue;
            } else if(token == ".."){
                if(st.size()!=0){
                    st.pop_back();
                }
            } else if(token!="") {
                
                st.push_back(token);
            }
        }
        
        string res="";
        
        for(auto x:st){
            res += "/" + x;
        }
        
        return res.length() == 0 ? "/" : res;
    }
};