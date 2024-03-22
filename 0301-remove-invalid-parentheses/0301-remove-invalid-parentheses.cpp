class Solution {
private:
    bool isValid(string s){
        int b=0;
        for(auto c:s){
            if(c=='('){
                b+=1;
            } else if(c == ')'){
                b-=1;
                if(b<0){
                    return false;
                }
            }
        }
        return b==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        unordered_map<string, bool> visited;
        
        vector<string> ans;
        visited[s] = true;
        bool found=false;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                
                auto f= q.front();
                q.pop();
                
                if(isValid(f)){
                    //cout<<"valid";
                    ans.push_back(f);
                    found = true;
                }
                
                for(int i=0;i<f.length();i++){
                    if(f[i] == '(' || f[i] == ')'){
                         string temp = f.substr(0, i) + f.substr(i+1);
                            if(!visited[temp]){
                                visited[temp] = true;
                                q.push(temp);
                            }
                    }
                   
                }
                
                
            }
            
            if(found){
                
                return ans;
            }
        }
        
        return ans;
        
    }
};