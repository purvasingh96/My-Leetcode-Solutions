class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq=0;
        unordered_map<char, int> m;
        int maxLen = 0;
        int l=0, r=0;
        
        for(;r<s.length();r++){
            m[s[r]]+=1;
            maxFreq = max(maxFreq, m[s[r]]);
            
            int len = r-l+1;
            if(len - maxFreq <= k){
                maxLen = max(maxLen, r-l+1);
            } else {
                
                    m[s[l]]-=1;
                    l+=1;
                
                
            }
            
            
        }
        
        return maxLen;
        
    }
};