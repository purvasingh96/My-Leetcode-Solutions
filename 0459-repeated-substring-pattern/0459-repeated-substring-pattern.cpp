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
    bool repeatedSubstringPattern(string s) {
        // generate LPS
        // k = length - lps.back
        // n%k!=0 => false
        // check for s.substr(0, k) * n/k  == s => true;
        
        vector<int> lps = generateLPS(s);
        if(lps.back() == 0) return false;
        int n = s.length();
        int k = n-lps.back();
        
        return n%k==0;
        
    }
};