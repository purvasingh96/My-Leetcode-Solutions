class Solution {
private:
    vector<int> generateLPS(string s){
        int n = s.length();
        vector<int> lps(n, 0);
        int j=0, i=1;
        while(i<n){
            if(s[i] == s[j]){
                lps[i] = j+1;
                i+=1;
                j+=1;
            } else{
                if(j>0){
                    j = lps[j-1];
                } else{
                    i+=1;
                }
            }
        }
        return lps;
    }
    
public:
    int strStr(string h, string s) {
        vector<int> lps = generateLPS(s);
        
        int i=0, j=0;
        
        while(i<h.length()){
            if(h[i]==s[j]){
                i+=1;
                j+=1;
            } else{
                if(j>0){
                    j = lps[j-1];
                } else{
                    i+=1;
                }
            }
            if(j==s.length()) return i-s.length();
        }
        
        return -1;
    }
};