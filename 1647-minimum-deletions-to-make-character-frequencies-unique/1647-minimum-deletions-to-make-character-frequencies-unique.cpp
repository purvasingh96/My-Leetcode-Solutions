class Solution {
public:
    int minDeletions(string s) {
        vector<int> t(26, 0);
        int n=0;
        
        for(auto c:s){
            t[c-'a']+=1;
            n = max(n, t[c-'a']);
        }
        
        // for(int i=0;i<26;i++){
        //     cout<<t[i]<<" ";
        // }
        
        vector<int> freq(n+1, -1);
        
        int i=0;
        int left=0, right=0;
        int count=0;
        
        
        for(int i=0;i<26;i++){
            
            if(t[i]!=-1){
                
                if(freq[t[i]]==-1){
                    freq[t[i]]=1;
                } else{
                    
                    while(t[i] >0 && freq[t[i]]!=-1){
                        
                        count+=1;
                        t[i]-=1;
                        
                    }
                    
                    if(t[i]>0) freq[t[i]] = 1;
                    
                }
                
            }
            
        }
        
        
        return count;
        
    }
};