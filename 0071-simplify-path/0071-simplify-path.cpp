class Solution {
public:
    string simplifyPath(string path) {
        if(path.back()!='/') path += "/";
        stack<string> st;
        int n = path.length();
        int i=1;
        // path will always start with /
        st.push("/");
        
        while(i<n){
            if(st.top() == "/"){
                if(path[i]=='/') {
                    i+=1;
                    continue;
                }
                
                else if(path[i]=='.'){
                    if(i+2<n && path.substr(i, 3)=="../"){
                        if(!st.empty()) st.pop();
                        if(!st.empty()) st.pop();
                        i+=2;
                    } 
                    
                    else if(i+1<n && path.substr(i, 2)=="./"){
                        i+=1;
                    }
                    
                    else {
                        string temp="";
                        while(path[i]!='/'){
                            temp.push_back(path[i]);
                            i+=1;
                        }
                            
                        st.push(temp);
                    }
                    i+=1;
                } 
                
                
                else {
                    string temp="";
                    while(path[i]!='/'){
                        temp.push_back(path[i]);
                        i+=1;
                    }
                    i+=1;
                    st.push(temp);
                }
                
                if(st.empty() || st.top()!="/") st.push("/");
            }
        }
        
        
        stack<string> t;
        while(!st.empty()){
            t.push(st.top());
            st.pop();
        }
        
        
        
        string ans="";
        while(!t.empty()){
            if(t.top() == "/" && ans.back()=='/') {
                t.pop();
                continue;
            } else {
                ans += t.top();
                t.pop();
            }
        }
        
        
        if(ans.back() == '/') ans.pop_back();
        
        if(ans[0]!='/') ans = "/"+ans;
        //cout<<"ans: "<<ans;
        
        return ans;
        
    }
};