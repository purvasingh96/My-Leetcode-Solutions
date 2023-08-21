class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        if(s.length()<=1) return false;
        
        int n = s.length();
        //cout<<n<<"\n";
        vector<int> lps(n, 0);
        
        int i=0, j=1;
        
        while(j<s.length()){
            while(i>0 && s[i]!=s[j]){
                i = lps[i-1];
            }
            if(s[i] == s[j]){
                lps[j]=i+1;
                i+=1;
            }
            j+=1;
            //for(auto x:lps) cout<<x<<" ";
            //cout<<"\n";
        }
        
        if(lps.back() == 0) return false;
        
        for(auto x:lps) cout<<x<<" ";
        int t = n/(n - lps.back()); // 3
        int k = n - lps.back(); // 3
        string temp = s.substr(0, k);
        
        string res = "";
        while(t--){
            res += temp;
        }
        
        return res == s;
        
        
        
    }
};