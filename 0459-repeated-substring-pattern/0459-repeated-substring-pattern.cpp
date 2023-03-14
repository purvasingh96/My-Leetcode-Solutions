class Solution {
private:
    vector<int> generateLPS(string& s){
        int i=1, j=0, n = s.length();
        vector<int> lps(n, 0);
        while(i<n){
            if(s[i] == s[j]){
                lps[i]=j+1;
                i+=1;
                j+=1;
            } else{
                if(j>0) j = lps[j-1];
                else i+=1;
            }
        }
        return lps;
    }
public:
    bool repeatedSubstringPattern(string s) {
        vector<int> lps = generateLPS(s);
        if(lps.back() == 0) return false;
        int n = s.length();
        int len = n-lps.back();
        
        string temp = s.substr(0, len);
        int freq = n/(len);
        if(n%len!=0) return false;
        string ans="";
        while(freq--) ans += temp;
        return ans == s;
    }
};