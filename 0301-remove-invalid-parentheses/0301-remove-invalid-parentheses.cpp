class Solution {
private:
    bool isValid(string& s){
        int balance=0;
        for(int i=0;i<s.length();i++){
            if(s[i] == ')'){
                balance -=1;
                if(balance <0){
                    return false;
                }
            } else if(s[i] == '('){
                balance +=1;
            }
        }
        
        return balance == 0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        
        
        if(isValid(s)){
            vector<string> ans;
            ans.push_back(s);
            return ans;
        }
        unordered_set<string> res;
        unordered_map<string, bool> visited;
        while(!q.empty()){
            int sz = q.size();
            bool found=false;
            while(sz--){
                auto f=q.front();
                q.pop();
                
                    for(int i=0;i<f.length();i++){
                        while(i<f.length()-1 && f[i] == f[i+1]){
                            i+=1;
                        }
                        if(f[i] == ')' || f[i] == '('){
                            string t = f.substr(0, i) + f.substr(i+1);
                            if(visited[t]==false){
                                visited[t] = true;
                                if(isValid(t)){
                                    found=true;
                                    res.insert(t);
                                } else {
                                    q.push(t);
                                }
                            }
                            
                            
                        }
                    }
                
            }
             if(found){
                    vector<string> ans(res.begin(), res.end());
                    return ans;
                }
        }
        
        vector<string> ans(res.begin(), res.end());
        
        return ans;
    }
};