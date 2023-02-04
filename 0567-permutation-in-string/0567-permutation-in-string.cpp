class Solution {
private:
    bool isPerm(vector<int>& res1, vector<int>& res2){
        for(int i=0;i<26;i++){
            if(res1[i]!=0){
                if(res1[i] != res2[i]) return false;
            }
        }
        
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> res1(26,0);
        vector<int> res2(26, 0);
        
        int m = s1.length(), n = s2.length();
        for(auto c:s1) res1[c-'a']+=1;
        
        for(int i=0;i<m;i++) res2[s2[i]-'a']+=1;
        
        int l=0, r=m-1;
        
        while(r<n){
            if(isPerm(res1, res2)) return true;
            else{
                r+=1;
                if(r<n){
                    res2[s2[r]-'a'] +=1;
                    res2[s2[l]-'a'] -=1;
                    l+=1;
                }
            }
        }
        
        return false;
        
    }
};