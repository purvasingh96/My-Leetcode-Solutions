class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        vector<int> lps(n, 0);
        
        for(int i=1,j=0;i<n;){
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
        
        return s.substr(0, lps.back());
    }
};