class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0;
        unordered_map<char, int> m;
        int len=0;
        
        for(;r<s.length();r++){
            m[s[r]]+=1;
            
            while(l<r && m[s[r]]>1){
                m[s[l]]-=1;
                l+=1;
            }
            
            len = max(len, (r-l+1));
        }
        
        return len;
        
    }
};