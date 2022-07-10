class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int capacity) {
        
        sort(b.begin(), b.end());
        sort(p.begin(), p.end());
        
        
        int idx=0, i=0;
        int ans = min(p[0]-1, b.back());
        
        
        for(i=0;i<b.size() && idx<p.size();i++){
            int cap = capacity;
            
            while(cap && idx<p.size() && p[idx] <= b[i]){
                if(idx!=0 && p[idx]-p[idx-1]>1){
                    ans = p[idx]-1;
                }
                cap-=1;
                idx+=1;
            }
            
            if(cap!=0){
                if(idx>0 && p[idx-1]!=b[i]){
                    ans = b[i];
                }
            }
            
            
        }
        
        if(i!=b.size()){
            ans = b.back();
        }
        return ans;
    }
};