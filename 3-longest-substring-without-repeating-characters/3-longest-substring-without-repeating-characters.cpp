class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> m(128, -1);
        int left=0;
        int max_len=0;
   
        for(int right=0;right<s.length();right++) {
            
            int asc = (int)s[right];
            if(m[asc] != -1)  {
                
                left = max(m[asc], left);
                
                
            }
            
            
            m[asc] = right+1;
            int cur_len = right-left+1;
            max_len = max(max_len, cur_len);
            
        }
        
        return max_len;
        
    }
};