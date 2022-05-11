class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> endsWith(n, vector<int>(5, 0));
        int ans=0;
        // base case
        for(int j=0;j<5;j++) {
            endsWith[0][j]=1;
        }
        
        for(int i=0;i<n;i++) {
            endsWith[i][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<5;j++) {
                for(int k=j;k>=0;k--){
                    endsWith[i][j] += endsWith[i-1][k];
                }
            }
        }
        
        for(int j=0;j<5;j++){
            ans += endsWith[n-1][j];
        }
        
        
        
        return ans;
        
    }
};