class Solution {
private:
    vector<int> generateLPS(string s){
        int n =s.length();
        vector<int> lps(n, 0);
        int i=1, j=0;
        while(i<n){
            if(s[i]==s[j]){
                lps[i] =  j+1;
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
    string shortestPalindrome(string s) {
        // find idx = lps of s + "#" + rev(s)
        // rev(s.substr(idx)) + OG s
        string og = s;
        reverse(s.begin(), s.end());
        string temp = og + "#" + s;
        vector<int> lps = generateLPS(temp);
        int idx = lps.back();
        string x = og.substr(idx);
        reverse(x.begin(), x.end());
        return x + og;
        
    }
};