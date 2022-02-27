class Solution {
public:
    bool checkPal(string s) {
        int left=0, right=s.length()-1;
        
        while(left < right) {
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    
    bool validPalindrome(string s) {
        
        int left=0, right=s.length()-1;
        
        while(left < right) {
            
            if(s[left] != s[right]) {
                
                string a = s.substr(left, (right-left));
                string b = s.substr(left+1, (right-left));
                
                return (checkPal(a) || checkPal(b));
                
            } 
            
            left+=1;
            right-=1;
            
        }
        
        return true;
        
    }
};