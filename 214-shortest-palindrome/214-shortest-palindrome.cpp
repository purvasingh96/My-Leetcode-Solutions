class Solution {
private:
    int generateLPS(string s){
        int j=0, n = s.length();
        vector<int> lps(n, 0);
        
        for(int i=1;i<s.length();){
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
 
        
        return lps.back();
    }
public:
    string shortestPalindrome(string s) {
        string og = s;
        reverse(s.begin(), s.end());
        string new_s = og + "#" + s;
        int lps = generateLPS(new_s);
        
        //cout<<lps;
        return s.substr(0, s.length()-lps) + og;
    }
};