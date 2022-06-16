class Solution {
private:
    int dp[501][51][2][2] = {};
    int dfs(int i, int evilpos, int leftbound, int rightbound, int n, string s1, string s2, string evil, vector<int>& lps){
        
        if(evilpos == evil.length()){
            return 0;
        }
        
        if(i==n){
            return 1;
        }
        
        if(dp[i][evilpos][leftbound][rightbound]!=0){
            return dp[i][evilpos][leftbound][rightbound];
        } 
        
        char from = leftbound?s1[i]:'a';
        char to = rightbound?s2[i]:'z';
        int res=0;
        for(char c = from;c<=to;c++){
            
            int j = evilpos;
            while(j>0 && c!=evil[j]) j=lps[j-1];
            
            if(c==evil[j]) j+=1;
            
            res += dfs(i+1, j, (leftbound && c==from), (rightbound && c==to), n, s1, s2, evil, lps);
            res%=1000000007;
            
        }
        
        return dp[i][evilpos][leftbound][rightbound] = res;
        
    }
    vector<int> generateLPS(string evil){
        int n = evil.length();
        vector<int> lps(n, 0);
        for(int j=0, i=1;i<n;){
            if(evil[i] == evil[j]){
                lps[i] = j+1;
                i+=1;
                j+=1;
            }else{
                if(j>0) j = lps[j-1];
                else i+=1;
            }
        }
        return lps;
    }
public:
    int findGoodStrings(int n, string s1, string s2, string evil) {
        vector<int> lps = generateLPS(evil);
        int res=0;
        return dfs(0, 0, true, true, n, s1, s2, evil, lps);
        
    }
};