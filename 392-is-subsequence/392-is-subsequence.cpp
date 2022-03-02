class Solution {
public:
    bool isSubsequence(string s, string t) {
        int left=0, right=0;
        
        while(left<s.length() && right<t.length()) {
            
            if(s[left] == t[right]) {
                left+=1;
            }
            
            right+=1;
        }
        
        return left == s.length();
    }
};