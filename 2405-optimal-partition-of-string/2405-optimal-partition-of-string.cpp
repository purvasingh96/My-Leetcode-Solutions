class Solution {
public:
    int partitionString(string s) {
        vector<int> c(26, 0);
        int ans=0;
        
        for(int i=0;i<s.length();i++){
            int idx = s[i]-'a';
            if(c[idx]>0) {
                ans+=1;
                for(int i=0;i<26;i++) c[i]=0;
                c[idx]=1;
            } else {
                c[idx]+=1;
            }
        }
        return ans+1;
    }
};