class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        
        int i=0, j=0;
        
        while(i<word.length() && j<abbr.length()) {
            
            if(isdigit(abbr[j])) {
                
                if(abbr[j] == '0') return false;
                
                int digit=0;
                
                while(j<abbr.length() && isdigit(abbr[j])) {
                    
                    digit = (digit*10) + abbr[j] - '0';
                    j+=1;
                    
                }
                
                i += digit;
                
                
            }
            
            else if(word[i++] != abbr[j++]) return false;
            
        }
        
        return i== word.length() && j==abbr.length();
        
    }
};