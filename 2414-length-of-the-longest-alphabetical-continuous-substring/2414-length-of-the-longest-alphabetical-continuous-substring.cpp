class Solution {
public:
    int longestContinuousSubstring(string s) {
        // sliding window
        if(s.length() == 1) return 1;
        int l=0, r=1;
        int n = s.length();
        int ans=0;
        while(r<n){
            while(s[r]-s[r-1]==1){
                r+=1;
            }
            ans = max(ans, (r-l));
            l=r;
            r+=1;
        }
        
        return ans;
    }
};