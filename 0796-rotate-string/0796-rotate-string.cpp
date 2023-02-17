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
    bool rotateString(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        int n = s.length();
        string temp = s + "#" + goal;
        auto lps = generateLPS(temp);
        int len=lps.back();
        return len>0 && s.substr(len) == goal.substr(0, (n-len));
    }
};