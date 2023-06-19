class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        s+=s;
        
        string s1="", s2="";
        
        for(int i=0;i<s.length();i++){
            i%2==0?s1.push_back('1'):s1.push_back('0');
            i%2==0?s2.push_back('0'):s2.push_back('1');
        }
        
        int ans1=0, ans2=0, ans=INT_MAX;
        
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s[i]) ans1+=1;
            if(s2[i]!=s[i]) ans2+=1;
            
            if(i>=n){
                if(s1[i-n]!=s[i-n]) ans1-=1;
                if(s2[i-n]!=s[i-n]) ans2-=1;
            }
            
            if(i>=n-1) {
                ans = min({ans, ans1, ans2});
            }
            
        }
        
        return ans;
    }
};