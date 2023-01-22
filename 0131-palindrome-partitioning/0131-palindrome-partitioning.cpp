class Solution {
private:
    bool isPal(string s){
        int n = s.length();
        int i=0, j = n-1;
        
        while(i<j){
            if(s[i] == s[j]) {
                i+=1;
                j-=1;
            } else return false;
        }
        
        return true;
    }
    
    void dfs(string s, int lastpos, int& total_len, vector<string>& temp, vector<vector<string>>& res){
        
        if(total_len == s.length()){
            res.push_back(temp);
            return;
        }
        
        if(lastpos == s.length()){
            return;
        }
        
        
        for(int len=1;len<=(s.length() - lastpos);len++){
                
                string sub = s.substr(lastpos, len);
                if(isPal(sub)){
                    total_len += sub.length();
                    temp.push_back(sub);
                    dfs(s, lastpos+len, total_len, temp, res);
                    temp.pop_back();
                    total_len -= sub.length();
                }
                
            }
        
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        int tl=0;
        dfs(s, 0,tl,  temp, res);
        return res;
    }
};