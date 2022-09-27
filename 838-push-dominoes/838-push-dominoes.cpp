class Solution {
public:
    string pushDominoes(string s) {
        string l(1, 'L');
        string r(1, 'R');
        
        s = l + s + r;
        int n = s.length();
        char last_char = 'L';
        int j=0;
        
        for(int i=1;i<n;i++){
            
            if(s[i]=='.') continue;
            
            else if(s[i]=='L'){
                if(last_char=='L') for(int k=i-1;k>j;k--) s[k]='L';
                else {
                    int mid = j + (i-j)/2;
                    
                    for(int k=j+1;k<=mid;k++) s[k]='R';
                    for(int k=i-1;k>mid;k--) s[k]='L';
                    
                    if((i-j-1)%2!=0) s[mid]='.';
                }
                
                last_char='L';
                j=i;
                
            } else if(s[i]=='R'){
                if(last_char=='R'){
                    for(int k=j+1;k<i;k++) s[k]='R';
                }
                last_char='R';
                j=i;
            }
            
            
        }
        
        s.pop_back();
        return s.substr(1);
    }
};