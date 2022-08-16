class Solution {
private:
    void dfs(int pi, string pattern, string temp, int& minres, vector<bool>& seen){
        if(pi==pattern.length()){
            minres = min(minres, stoi(temp));
            return;
        }
        
        int start = temp.back()-'0';
        
        if(pattern[pi] == 'I'){
            
            for(int i=start+1;i<=9;i++){
                if(!seen[i]){
                    seen[i] = true;
                    temp += (i+'0');
                    dfs(pi+1, pattern, temp, minres, seen);
                    temp.pop_back();
                    seen[i]=false;
                }
            }
            
        } else {
            
            for(int i=start-1;i>0;i--){
                if(!seen[i]){
                    seen[i]=true;
                    temp += (i+'0');
                    dfs(pi+1, pattern, temp, minres, seen);
                    temp.pop_back();
                    seen[i]=false;
                }
            }
            
        }
        
        
    }
public:
    string smallestNumber(string pattern) {
        int minres=INT_MAX;
        int ans=INT_MAX;
        
        for(int i=1;i<=9;i++){
            vector<bool> seen(10, false);
            
            string temp = "";
            temp += (i+'0');
            seen[i] = true;
            dfs(0, pattern, temp, minres, seen);
            
            ans = min(ans, minres);
        }
        
        return to_string(ans);
    }
};