class Solution {
private:
    bool isValid(string s){
        int balance=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                balance+=1;
            } else if(s[i] == ')') {
                balance-=1;
                if(balance < 0){
                    return false;
                }
            }
        }
        
        return balance==0;
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> q;
        q.push(s);
        unordered_map<string, bool> visited;
        bool found=false;
        vector<string> res;
        visited[s] = true;
        
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto f = q.front();
                q.pop();
                
                if(isValid(f)){
                    found = true;
                    res.push_back(f);
                }
                
                for(int i=0;i<f.length();i++){
                    string left = f.substr(0, i);
                    string right = f.substr(i+1);
                    string temp = left+right;
                    if(!visited[temp]){
                        visited[temp] = true;
                        q.push(temp);
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