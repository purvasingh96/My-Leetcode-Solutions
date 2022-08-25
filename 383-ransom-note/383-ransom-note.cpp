class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> r(26, 0);
        vector<int> m(26, 0);
        
        for(auto x:ransomNote){
            r[x-'a']+=1;
        }
        
        for(auto x:magazine){
            m[x-'a']+=1;
        }
        
        for(int i=0;i<26;i++){
            if(r[i] > m[i]) return false;
        }
        
        return true;
    }
};