class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }
        
        int ans = s.length();
        
        for(int d=1;d<n;d++){
            for(int i=0;i+d<n;i++){
                int j = i+d;
                //cout<<"i: "<<i<<"j: "<<j<<"\n";
                if(s[i] == s[j]){
                    if((i+1 <= j-1 && dp[i+1][j-1]) || (j-i+1==2)){
                        ans+=1;
                        dp[i][j]=1;
                    } 
                }
            }
        }
        
//         for(auto x:dp){
//             for(auto y:x){
//                 cout<<y<<" ";
//             }
//             cout<<"\n";
//         }
        
        return ans;
        
    }
};