class Solution {
public:
    int strStr(string h, string n) {
        if(n.length() == 0) return 0;
        int i=0, j=0;
        int cur_pos = -1;
        
        while(i<h.length() && j<n.length()){
            
            if(h[i]==n[j]){
                int temp_i = i;
                while(temp_i<h.length() && j<n.length() && h[temp_i] == n[j]) {
                    temp_i+=1;
                    j+=1;
                }
                
                if(j!=n.length()) {
                    cur_pos=-1;
                    j=0;
                    
                } else{
                    cur_pos = i;
                    return cur_pos;
                }
                
            } 
            
            i+=1;
            
        }
        
        return -1;
    }
};