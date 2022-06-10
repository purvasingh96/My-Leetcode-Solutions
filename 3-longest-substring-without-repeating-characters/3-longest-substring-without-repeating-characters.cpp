class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int max_len = 0;
        int left=0;
        
        for(int right=0;right<s.length();right++){
            int asci = (int)s[right];
            
            if(m[asci]!=-1){
                left = max(left, m[asci]);
            }
            
            m[asci] = right+1;
            max_len = max(max_len, right-left+1);
        }
        
        return max_len;
    }
};