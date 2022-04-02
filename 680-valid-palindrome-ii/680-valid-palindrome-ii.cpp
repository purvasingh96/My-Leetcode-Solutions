class Solution {
public:
    bool checkPalindrome(string s, int l, int r) {
        while(l<r) {
            if(s[l]!=s[r]) return false;
            l+=1;
            r-=1;
        }
        return true;
    }
    
    
    bool validPalindrome(string s) {
        
        int l = 0, r=s.length()-1;
        
        while(l<r) {
            
            if(s[l]!=s[r]) {
                
                return (checkPalindrome(s, l, r-1) || checkPalindrome(s, l+1, r));
                
            }
            
            l+=1;
            r-=1;
            
        }
        
        return true;
        
    }
};