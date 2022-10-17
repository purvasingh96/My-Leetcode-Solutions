class Solution {
public:
    int largestVariance(string s) {
        
        int ans=0;
        
        for(int lfc=0;lfc<26;lfc++){
            for(int hfc=0;hfc<26;hfc++){
                
                if(lfc==hfc) continue;
                int lf=0, hf=0;
                bool lastLowFreqCharAbandoned=false;
                
                for(auto c:s){
                    int idx = c-'a';
                    
                    if(idx == lfc) lf+=1;
                    if(idx == hfc) hf+=1;
                    
                    
                    if(lf>0){
                        ans = max(ans, hf-lf);
                    }
                    
                    else {
                        
                        if(lastLowFreqCharAbandoned){
                            ans = max(ans, hf-1);
                        }
                        
                    }
                    
                    if(lf > hf){
                        lf=0;
                        hf=0;
                        lastLowFreqCharAbandoned = true;
                    }
                    
                }
                
            }
        }
        
        return ans;
        
    }
};