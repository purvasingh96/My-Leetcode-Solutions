class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.length()-1;
        
        while(left<right) {
            
            if(!isalnum(s[left])){
                while(left<right && !isalnum(s[left])) {
                    left += 1;
                }
            
            } 
            
            if(!isalnum(s[right])) {
                while(right>left && !isalnum(s[right])) {
                        right -= 1;
                    }
            }
            
            if(left == right) {
                
                return true;
                
                
            }
            
            if(isalpha(s[left]) && isupper(s[left])) s[left] = tolower(s[left]);
            if(isalpha(s[right]) && isupper(s[right])) s[right] = tolower(s[right]);
            
            if(s[left] != s[right]) return false;
            
            left +=1;
            right -= 1;
            
        }
        
        return true;
    }
};