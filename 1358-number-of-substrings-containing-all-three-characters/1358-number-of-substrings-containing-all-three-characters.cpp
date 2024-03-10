class Solution {

public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int sum=0, ans=0;
        int l=0, r=0;
        
        while(r<s.length()){
            count[s[r]-'a']+=1;
            
            while(l<r && count[0]>0 && count[1] >0 && count[2] >0){
                count[s[l]-'a']-=1;
                l+=1;
            }
            
            ans+=l;
            r+=1;
            
        }
        
        return ans;
        
    }
};