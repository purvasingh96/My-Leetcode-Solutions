class Solution {
public:
    int minSwaps(string s) {
        int left=0, right=s.length()-1;
        int count=0, swaps=0;
        
        
        
        for(int i=0;i<s.length();i++) {
            
            if(s[i] == ']') {
                if(count>0) count-=1;
                else {
                    
                    while(right>i && s[right]==']') {
                        right-=1;
                    }
                    
                    swap(s[i], s[right]);
                    swaps+=1;
                    count+=1;
                } 
            } else {
                    count+=1;
                }
            
        }
        
        return swaps;
    }
};