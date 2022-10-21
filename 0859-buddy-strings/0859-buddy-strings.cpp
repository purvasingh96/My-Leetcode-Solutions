class Solution {
public:
    bool buddyStrings(string s, string goal) {
        
        int s1=-1, s2=-1;
        if(s.length()!=goal.length()) return false;
        int count=0;
        
        bool hasEvenCount=false;
        vector<int> c(26, 0);
        
        for(int i=0;i<s.length();i++){   
            c[s[i]-'a'] +=1;
            if(c[s[i]-'a']%2==0) hasEvenCount=true;
            if(s[i]!=goal[i]){
                if(s1==-1) s1=i;
                else s2=i;
                count+=1;
                if(count > 2) return false;
            }
            
        }
        
        if(count==1) return false;
        
        if(count==0) return hasEvenCount;
        
        return goal[s1]==s[s2] && goal[s2] == s[s1];
        
    }
};