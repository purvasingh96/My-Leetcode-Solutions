class Solution {
public:
    bool isPalindrome(string s) {
        int left=0, right=s.length()-1;
        
        while(left<right) {
            
            
                while(left<right && !isalnum(s[left])) {
                    left += 1;
                }
            
            
            
            
                while(right>left && !isalnum(s[right])) {
                        right -= 1;
                    }
            
      
            
            if(tolower(s[left]) != tolower(s[right]) ) return false;
            
            left +=1;
            right -= 1;
            
        }
        
        return true;
    }
};