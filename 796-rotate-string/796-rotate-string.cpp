class Solution {
private:
    vector<int> genrateLPS(string s){
        int n = s.length();
        vector<int> lps(n, 0);
        
        for(int i=1, j=0;i<n;){
            
            if(s[i] == s[j]){
                lps[i]=j+1;
                i+=1;
                j+=1;
            } else{
                
                if(j>0){
                    j=lps[j-1];
                } else{
                    i+=1;
                }
                
            }
            
        }
        
        return lps;
    }
public:
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        s = s+s;
        
        auto lps = genrateLPS(s);
        
        for(int i=0, j=0;i<lps.size();){
            
            if(s[i] == goal[j]){
                i+=1;
                j+=1;
            } else{
                if(j>0){
                    j = lps[j-1];
                } else{
                    i+=1;
                }
            }
            
            if(j==goal.length()) return true;
        }
        return false;
    }
};