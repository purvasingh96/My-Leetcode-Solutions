class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        vector<int> count1(26, 0);
        vector<int> count2(26, 0);
        int m = s1.length(), n = s2.length();
        int l=0, r=0;
        
        for(auto c:s1) count1[c-'a']+=1;
        for(;r<m;r++) count2[s2[r]-'a']+=1;
        
        if(count1 == count2) return true;
        
        for(;r<s2.length();r++){
            count2[s2[r]-'a']+=1;
            count2[s2[l]-'a']-=1;
            l+=1;
            
            if(count1==count2) return true;
            
        }
        
        return false;
        
    }
};