class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.length()!=goal.length()) return false;
        
        vector<int> sc;
        
        for(int i=0;i<s.length();i++){
                if(s[i]!=goal[i]) {
                    if(sc.size()>2) return false;
                    else{
                    sc.push_back(i);
                } 
            }
        }
        
        if(sc.size()==0)
        {
            vector<int> count(26, 0);
            for(auto c:s){
                count[c-'a']+=1;
                if(count[c-'a']%2==0) return true;
            }
            return false;
        }        
            
            
            
        else if(sc.size()==2){
            //cout<<sc[0]<<" "<<sc[1];
            char char0 = s[sc[0]];
            char char1 = s[sc[1]];
            //cout<<char0<<" "<<char1<<"\n";
            s[sc[0]] = char1;
            s[sc[1]] = char0;  
        }
        
        
        return s == goal;
        
    }
};