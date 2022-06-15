class Solution {
private:
    vector<int> generateLPS(string s){
        int j=0, n = s.length();
        vector<int> lps(n, 0);
        
        for(int i=1;i<n;){
            if(s[i] == s[j]){
                lps[i] = j+1;
                i+=1;
                j+=1;
            } else {
                if(j>0){
                    j=lps[j-1];
                } else{
                    i+=1;
                }
            }
        }
        return lps;
    }
public:
    bool repeatedSubstringPattern(string s) {
        auto lps = generateLPS(s);
        int i=0;
        if(lps.back() == 0) return false;
        while(i<lps.size() && lps[i]==0){
            i+=1;
        }
        return lps.size()%(lps.size()-lps.back())==0;
    }
};