class Solution {
public:
    int largestVariance(string s) {
        int ans=0;
        // i = high freq, j = low freq
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                
                if(i==j) continue;
                
                int hf=0, lf=0;
                bool lfcAbandonded=false;
                
                for(auto c:s){
                    
                    int k = c-'a';
                    
                    if(k==i) hf+=1;
                    if(k == j) lf+=1;
                    
                    if(lf>0){
                        ans = max(ans, hf-lf);
                    } else {
                        if(lfcAbandonded){
                            ans = max(ans, hf-1);
                        }
                    }
                    
                    if(lf > hf){
                        lf=0;
                        hf=0;
                        lfcAbandonded=true;
                    }
                    
                }
                
            }
        }
        
        return ans;
        
    }
};