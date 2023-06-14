class Solution {
private:
    
public:
    string minWindow(string s, string t) {
        int left=0, right=0;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        
        for(auto c:t) m2[c] += 1;
        
        int n = s.length();
        int len = INT_MAX;
        string temp="";
        string ans="";
        int c=0;
        
        while(right < n){
            if(m2.find(s[right])!=m2.end()){
                m1[s[right]]+=1;
                if(m1[s[right]] <= m2[s[right]]){
                    c+=1;
                }
            }
            
            if(c >= t.length()){
               
            while(left < right &&
                  (m2.find(s[left])==m2.end() || m1[s[left]] > m2[s[left]])){
                
                m1[s[left]]-=1;
                
                left+=1;
            }
            if((right-left+1) < len){
                len = (right-left+1);
                ans = s.substr(left, len);
            }
            
            
            }
            
            
            
            right+=1;
        }
        
        return len==INT_MAX ? "":ans;
        
    }
};