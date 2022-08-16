class Solution {
private:
    void revert(string& s, int start, int end){
        while(start<end){
            char t = s[start];
            s[start]=s[end];
            s[end]=t;
            start+=1;
            end-=1;
        }
    }
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string s ="";
        
        for(int i=0;i<=n;i++){
            s+= to_string(i+1);
        }
        int i=0;
        while(i<n){
            if(pattern[i]=='D'){
                int j=i;
                while(j<n && pattern[j]=='D'){
                    j+=1;
                }
                
                revert(s, i, j);
                i=j;
            } else {
                i+=1;
            }
        }
        
        return s;
        
    }
};