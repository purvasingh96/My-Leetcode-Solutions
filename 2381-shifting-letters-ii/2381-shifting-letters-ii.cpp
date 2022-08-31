class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // linesweep
        int n = s.length();
        
        vector<int> ps(n, 0);
        
        for(auto shift:shifts){
            int l = shift[0], r = shift[1], dir = shift[2];
            
            if(dir==1){
                ps[l]+=1;
                if(r+1<n) ps[r+1]-=1;
            } else{
                ps[l]-=1;
                if(r+1<n) ps[r+1]+=1;
            }
            
        }
        
        for(int i=1;i<n;i++){
            ps[i] += ps[i-1];
        }
        
        
        for(int i=0;i<n;i++){
            
            int inc = (s[i]-'a'+ps[i])%26;
            if(inc<0) inc+=26;
            inc = inc%26;
            s[i] = inc+'a';
            
        }
        
        return s;
        
    }
};