class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
        
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        int k=0, currCap=0, j;
        for(int i=0;i<b.size();i++){
            int idx = upper_bound(p.begin()+k, p.end(), b[i]) - p.begin();
                j=k;
                currCap = 0;
                while(j<idx && (j-k+1)<=c){
                    currCap = (j-k+1);
                    j+=1;
                }
            k=j;
            
        }
        
        int ans;
        if(currCap< c||j==0) ans = b.back();
        else ans = p[j-1];
        
        int idx = lower_bound(p.begin(), p.end(), ans) - p.begin();
        while(idx!=p.size() && p[idx]==ans){
            ans-=1;
            idx = lower_bound(p.begin(), p.end(), ans) - p.begin();
        }
        
        return ans;
        
        
    }
};