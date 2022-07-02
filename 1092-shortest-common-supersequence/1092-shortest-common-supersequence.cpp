class Solution {
private:
    string lcs(string s, string t, vector<vector<string>>& dp){
        int m = s.length(), n = t.length();
        
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                
                if(i==0 || j==0) dp[i][j] = "";
                
                else if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + s[i-1]);
                } else{
                    
                    if(dp[i-1][j].length() > dp[i][j-1].length()){
                        dp[i][j] = dp[i-1][j];
                    } else{
                        dp[i][j] = dp[i][j-1];
                    }
                    
                }
                
            }
        }
 
        return dp[m][n];
        
    }
public:
    string shortestCommonSupersequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<string>> dp(m+1, vector<string>(n+1, ""));
        //cout<<m<<" "<<n<<"\n";
        string lc =  lcs(s, t, dp);
        
        int i=0, j=0, k=0;
        string ans="";
        
        //cout<<lc;
        
        while(i<m && j<n && k<t.length()){
            
            if(s[i]==t[j]){  
                    ans+= s[i];
                    i+=1;
                    j+=1;
                    k+=1;
                } else {
                
                while(i<m && s[i]!=lc[k]){
                    ans+= s[i];
                    i+=1;
                } 
                
                while(j<n && t[j]!=lc[k]){
                    ans+= t[j];
                    j+=1;
                }
                
            } 
                
            }
        
        //cout<<i<<" "<<j;
        
        if(i<m){
            ans+= s.substr(i);
        }
        if(j<n){
            ans += t.substr(j);
        }
            return ans;
    }
};