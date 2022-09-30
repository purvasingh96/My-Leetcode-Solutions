class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0, n = nums.size(), maxlen=INT_MIN;
        vector<int> pre(31, 0);
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<31;j++){
                if(nums[i] & (1<<j)) pre[j] +=1;
            }
            
            int flag=true;
            for(int j=0;j<31;j++){
                if(pre[j]>1) {
                    flag=false;
                    break;
                }
            }
            
            if(flag) maxlen = max(maxlen, (i-l+1));
            
            else {
                
                
                while(l<=i){
                    
                    for(int j=0;j<31;j++){
                        if(nums[l] & (1<<j)) pre[j]-=1;
                    }
                    l+=1;
                    bool flag=true;
                    
                    for(int j=0;j<31;j++){
                        if(pre[j]>1) {
                            flag=false;
                            break;
                        }
                    }
                    
                    if(flag) break;
                    
                    
                }
                
                
            }
            
        }
        
        return maxlen;
    }
};