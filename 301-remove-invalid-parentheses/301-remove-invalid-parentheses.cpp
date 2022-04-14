class Solution {
private:
    char checkInvalidBrackets(string s) {
        int count=0;
        for(char c:s) {
            if(c == '(') count+=1;
            else if(c == ')') {
                if(count>0) count-=1;
                else return ')';
            }
        }
        
        return count==0?1:'(';
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        
        vector<string> res;
        queue<string> q;
        q.push(s);
        unordered_set<string> visited;
        visited.insert(s);
        
        while(!q.empty()) {
            
            int s = q.size();
            
            for(int i=0;i<s;i++) {
                
                
                string f = q.front();
                q.pop();
                
                // completly valid string
                char invalid = checkInvalidBrackets(f);
                if(invalid == 1) res.push_back(f);
                
                if(res.size()!=0) continue;
                
                for(int j=0;j<f.length();j++) {
                    
                    if(f[j] == invalid) {
                        string snew = f.substr(0, j) + f.substr(j+1);
                        
                        if(!visited.count(snew)) {
                            q.push(snew);
                            visited.insert(snew);
                        }
                    }
                    
                }
                
                if(res.size()) break;
                
            }
            
        }
        
        return res;
        
    }
};