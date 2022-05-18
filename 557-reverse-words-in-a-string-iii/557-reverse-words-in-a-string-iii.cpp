class Solution {
public:
    string reverseWords(string s) {
        
        int left=0, right=0;
        
        while(left<s.length()){
            
            if(s[left]!=' '){
                
                while(right<s.length() && s[right]!=' '){
                
                    right+=1;
                
                }

                reverse(s.begin()+left, s.begin()+right);
                left = right;
                
            } else{
                left+=1;
                right=left;
            }
            
            
            
        }
        
        return s;
        
    }
};