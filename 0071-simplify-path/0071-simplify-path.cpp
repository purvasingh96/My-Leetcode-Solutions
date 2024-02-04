class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string res="/";
        
        // split based on "/"
        stringstream ss(path);
        
        string token;
        
        while(getline(ss, token, '/')){
         if(token!=""){
             if(token == ".."){
                 // one directory up
                 if(st.size()!=0){
                     st.pop_back();
                 }
             } else if(token == ".") {
                 // curr directory
                 continue;
             }
             else {
                 st.push_back(token);
             }
         }
        }
        
        for(auto s:st){
            res += s; 
            res+="/";
        }
        
        if(res.length()>1){
            res.pop_back();
        }
        
        return res;
    }
};