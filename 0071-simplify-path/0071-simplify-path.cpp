class Solution {
public:
    string simplifyPath(string path) {
        stringstream ss(path);
        string token;
        string res  = "/";
        vector<string> st;
        
        while(getline(ss, token, '/')){
            //cout<<"token:: "<<token;
            if(token == "." || token == ""){
                continue;
            } else if(token == ".."){
                if(st.size()!=0){
                    st.pop_back();
                }
            } else {
                st.push_back(token);
            }
        }
        
        for(auto x:st){
            res += x + "/";
        }
        if(res.length()!=1){
            res.pop_back();
        }
        return res;
    }
};