class Solution {
private:
    vector<int> generateLPS(string& s){
        int n = s.length();
        vector<int> lps(n, 0);
        int i=1, j=0;
        while(i<n){
            if(s[i] == s[j]){
                lps[i]=j+1;
                j+=1;
                i+=1;
            } else{
                if(j==0) i+=1;
                else j = lps[j-1];
            }
        }
        
        return lps;
    }
public:
    int strStr(string haystack, string needle) {
        vector<int> s = generateLPS(needle);
        int n = needle.length();
        
        int i=0, j=0;
        while(i<haystack.length()){
            if(haystack[i] == needle[j]){
                j+=1;
                i+=1;
                if(j==n) return (i-n);
            } else{
                if(j==0) {
                    i+=1;
                } else{
                    j = s[j-1];
                }
            }
        }
        
        return -1;
    }
};