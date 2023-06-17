class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0;
        unordered_map<char, int> m;
        int maxLen = 0;
        int l=0, r=0;
        
        for(;r<s.length();r++){
            m[s[r]]+=1;
            for(auto x:m) maxFreq = max(maxFreq, x.second);
            
            int len = r-l+1;
            if(len - maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
            } else {
                
                while(l<r && len - maxFreq > k){
                    m[s[l]]-=1;
                    for(auto x:m){
                        maxFreq = max(maxFreq, x.second);
                    }
                    l+=1;
                    len = r-l+1;
                }
                
            }
            
            maxLen = max(maxLen, r-l+1);
        }
        
        return maxLen;
        
    }
};