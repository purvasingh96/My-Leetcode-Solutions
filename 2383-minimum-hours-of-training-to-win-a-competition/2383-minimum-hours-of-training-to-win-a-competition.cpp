class Solution {
public:
    int minNumberOfHours(int en, int ex, vector<int>& energy, vector<int>& experience) {
        int eh = 0, ans=0;
        
        int te = accumulate(energy.begin(), energy.end(), 0);
        
        int diff = te-en;
        
        ans += (diff>=0) ? diff+1:0;
        
        int t=INT_MIN;
        int expH = ex;
        
        for(int i=0;i<experience.size();i++){
            
            if(expH <= experience[i]){
                t = max(t, experience[i]+1-expH);
            }
            
            expH += experience[i];
            
        }
        
        ans += (t==INT_MIN)?0:t;
        
        return ans;
        
    }
};