class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int need = 1<<k;
        int allOnes = need-1;
        map<int, bool> got;
        int hash=0;
        
        for(int i=0;i<s.length();i++){
            hash = ((hash<<1) & allOnes | (s[i]-'0'));
            if(i>=k-1 && !got[hash]){
                got[hash]=true;
                need-=1;
                if(need==0){
                    return true;
                }
            }
        }
        
        return false;
    }
};