class Solution {
public:
    string pushDominoes(string d) {
        string x = "L" + d + "R";
        int left=0, right=0;
        d=x;
        
        for(int i=0;i<d.length();i++){
            
            if(d[i]!='.') left=i;
            
            else if(d[i] == '.') {
                for(int k=i+1;k<d.length();k++){
                    if(d[k]!='.') {
                        right=k;
                        break;
                    }
                }
                if(d[left] == 'R' && d[right] == 'L'){
                    while(left<right){
                        d[left++] = 'R';
                        d[right--] = 'L';
                    }
                } 
                
                else if(d[left] == 'L' && d[right]=='L'){
                    while(right>left) d[right--] = 'L';
                } 
                
                else if(d[left] == 'R' && d[right]=='R'){
                    while(left<right) d[left++]='R';
                }
                
                i=right-1;
            }
            
            
        }
        
        string res = d.substr(1);
        res.pop_back();
        
        return res;
        
    }
};