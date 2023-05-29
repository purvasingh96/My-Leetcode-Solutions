typedef long long ll;
class Solution {
public:
    long long minimumCost(string s) {
        if(s.length()==1) return 0;
        int n = s.length();
        vector<ll> ps(n, 0);
        
        for(int i=1;i<n;i++){
            if(s[i] !=s[i-1]){
                ps[i] = ps[i-1] + i;
            } else {
                ps[i] = ps[i-1];
            }
        }
        
        ll ss=0;
        ll ans=1e14;
        
        for(int i=n-2;i>=0;i--){
            if(s[i]!=s[i+1]){
                ss += (n-i-1);
            }
            ans = min(ans, ps[i]+ss);
        }
        
        return ans;
    }
};