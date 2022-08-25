class Solution {
private:
    int longestPalindromicSubstring(string s){
        int n = s.length();
        vector<int> lps(n,0);
        int maxlen = 0;
        
        for(int i=1, j=0;i<n;){
            if(s[j] == s[i]){
                lps[i]=j+1;
                maxlen = max(maxlen, lps[i]);
                i+=1;
                j+=1;
            } else {
                
                if(j>0){
                    j=lps[j-1];
                } else {
                    i+=1;
                }
                
            }
        }
        
        return lps.back();
        
    } 
public:
    string shortestPalindrome(string s) {
        // find longest palindromic substring from begininng
        // reverse rest of the string and append in front
        string og = s;
        reverse(s.begin(), s.end());
        string target = og + '#' + s;
        
        int len = longestPalindromicSubstring(target);
        //cout<<len;
        
        string left = og.substr(0, len);
        
        
        string right = og.substr(len);
        //cout<<"left: "<<left<<" "<<"right: "<<right<<"\n";
        reverse(right.begin(), right.end());
        
        return right+og;
        
        
        
    }
};