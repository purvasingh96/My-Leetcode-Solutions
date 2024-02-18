class Solution {
private:
    bool isvalid(string s){
        stack<char> st;
        for(auto c:s){
            if(c=='('){
                st.push(c);
            } else if(c == ')'){
                if(!st.empty() && st.top() == '('){
                    st.pop();
                } else {
                    st.push(c);
                }
            }   
        }
        return st.empty();
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        vector<string> res;
        unordered_map<string, bool> visited;
        visited[s]=true;
        bool found=false;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                //cout<<"f:: "<<f;
                if(isvalid(f)){
                    //cout<<"f:: "<<f<<"\n";
                    found=true;
                    res.push_back(f);
                } else{
                    for(int i=0;i<f.length();i++){
                        string left = f.substr(0, i);
                        string right = f.substr(i+1);
                        string temp = left+right;
                        if(visited[temp] == false){
                            visited[temp] = true;
                            q.push(temp);    
                        }
                        
                    }
                }
                    
            }
            if(found){
                break;
            }
        }
        return res;
    }
};