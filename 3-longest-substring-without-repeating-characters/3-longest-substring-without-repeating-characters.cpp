class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char, int> m;
        int left=0;
        int max_len=0;
        
        for(int right=0;right<s.length();right++) {
            
            if(m[s[right]] == 1)  {
                
                while(left <= right && m[s[right]] == 1) {
                    
                    m[s[left]] -= 1;
                    left+=1;
                    
                    
                }
                
                
            }
            
            
            m[s[right]] += 1;
            int cur_len = right-left+1;
            max_len = max(max_len, cur_len);
            
        }
        
        return max_len;
        
    }
};