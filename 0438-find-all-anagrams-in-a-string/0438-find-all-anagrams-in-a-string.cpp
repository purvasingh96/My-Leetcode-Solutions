class Solution {

public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        // sliding window
        vector<int> pc(26, 0);
        vector<int> sc(26, 0);
        
        int n = p.length();
        int left=0, right=n-1;
        
        for(auto c:p) pc[c-'a']+=1;
        
        for(int i=0;i<n;i++){
            sc[s[i]-'a'] += 1;
        }
        
        //cout<<"working";
        
        vector<int> res;
        
        while(right<s.length()){
            if(pc==sc){
              res.push_back(left);
                //cout<<"equal\n";
            } 
            
            right+=1;
            if(right<s.length()){
               sc[s[right]-'a']+=1;
                sc[s[left]-'a']-=1;
                left+=1; 
            }
            
        }
        
        return res;
        
    }
};