class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        // line sweep
        int n = s.length();
        vector<int> ps(n, 0);
        
        for(int i=0;i<shifts.size();i++){
            
            int l = shifts[i][0], r = shifts[i][1], dir = shifts[i][2];
            
            if(dir==1){
                ps[l] += 1;
                if(r+1<n) ps[r+1]-=1;
            } else {
                ps[l]-=1;
                if(r+1<n) ps[r+1]+=1;
            }
            
        }
        
        for(int i=1;i<n;i++){
            ps[i] += ps[i-1];
        }
        for(int i=0;i<n;i++){
            int increaseBy = (s[i]-'a'+ps[i])%26;
            if(increaseBy<0) increaseBy+=26;
            increaseBy%=26;
            s[i] = 'a'+increaseBy;
        }
        
        return s;
        
    }
};